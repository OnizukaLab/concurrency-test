#!/usr/bin/zsh

suffix=`date +%s`
nprocessor=`lscpu | grep -oP "^Core\(s\) per socket:\s+\d+" | sed -r "s/.+([0-9]+)/\1/"`
nsocket=`lscpu | grep -oP "^Socket\(s\):\s+\d+" | sed -r "s/.+([0-9]+)/\1/"`
ncores=$(($nprocessor * $nsocket))
targets=({0..6})
if [[ $# -ne 0 ]]; then;
  targets=($@)
fi;

for i in $targets; do;
  mkdir -p ../result/chunk/{cache,ahs,tsx}
  for ((j = 1; j <= 128; j *= 2)); do;
    perf stat -e cache-misses,cache-references,L1-dcache-loads,L1-dcache-load-misses \
      ../concurrency-test $i 1000000 $ncores 1000 1000 8 $j 0.2 >> ../result/chunk/cache/$i.$suffix 2>&1
    amplxe-cl -r=../result/chunk.cellar/ahs/$i/$j -c advanced-hotspots ../concurrency-test $i 1000000 $ncores 1000 1000 8 $j 0.2 \
      >> ../result/chunk/ahs/$i.$suffix
    if [[ $i -eq 2 || $i -eq 3 || $i -eq 4 ]]; then;
      amplxe-cl -r=../result/chunk.cellar/tsx/$i/$j -c tsx-exploration ../concurrency-test $i 1000000 $ncores 1000 1000 8 $j 0.2 \
        >> ../result/chunk/tsx/$i.$suffix
    fi;
  done;
done;
