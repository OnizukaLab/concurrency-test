#!/usr/bin/zsh

nprocessors=`lscpu | grep -oP "^Core\(s\) per socket:\s+\d+" | sed -r "s/.+([0-9]+)/\1/"`
nsockets=`lscpu | grep -oP "^Socket\(s\):\s+\d+" | sed -r "s/.+([0-9]+)/\1/"`
ncores=$(($nprocessors * $nsockets))
result_dir=./result/`date +%s`
targets=({0..6})
if [[ $# -ge 1 ]]; then;
  result_dir=./result/$1
  if [[ $# -ge 2 ]]; then;
    targets=(${@:2})
  fi;
fi;

mkdir -p $result_dir/conc/{cache,ahs,tsx}
for i in $targets; do;
  for ((j = 1; j <= $ncores; j++)); do;
    perf stat -e cache-misses,cache-references,L1-dcache-loads,L1-dcache-load-misses \
      ./concurrency-test $i 1000000 $j 1000 1000 8 8 0.2 >> $result_dir/conc/cache/$i 2>&1
    amplxe-cl -r=$result_dir/conc.cellar/ahs/$i/$j -c advanced-hotspots ./concurrency-test $i 1000000 $j 1000 1000 8 8 0.2 \
      >> $result_dir/conc/ahs/$i
    if [[ 0 -le $i && $i -le 3 ]]; then;
      amplxe-cl -r=$result_dir/conc.cellar/tsx/$i/$j -c tsx-exploration ./concurrency-test $i 1000000 $j 1000 1000 8 8 0.2 \
        >> $result_dir/conc/tsx/$i
    fi;
  done;
done;
