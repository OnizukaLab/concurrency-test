#!/bin/zsh

type="`basename $0 .zsh`"
nprocessors=`lscpu | grep -oP "(?<=Core\(s\) per socket:\s{4})\d+"`
nsockets=`lscpu | grep -oP "(?<=Socket\(s\):\s{13})\d+"`
ncores=$(($nprocessors * $nsockets))
result_dir="result/`date +%s`/$type"
targets=({0..6})
if [[ $# -ge 1 ]]; then
  result_dir="result/$1/$type"
  if [[ $# -ge 2 ]]; then
    targets=(${@:2})
  fi
fi
work_dir="`dirname $0`"
cache_dir="$result_dir/cache"
tsx_dir="$result_dir/tsx"

command='./concurrency-test $i 1000000 $ncores 1000 0.5 1000 8 $j 0.2'

for i in $targets; do
  mkdir -p $result_dir/{cache,tsx}/$i
  for ((j = 1; j <= 128; j *= 2)); do
    $work_dir/agg.zsh \
      -a "[\d\.]+(?=\s% of all cache refs)" \
      "perf stat -e cache-misses,cache-references,L1-dcache-loads,L1-dcache-load-misses \
        `eval echo $command` > $cache_dir/$i/$j 2>&1" \
      "$cache_dir/$i/$j" \
      "^[\d\.]+" > $cache_dir/$i/_$j
    if [[ 0 -le $i && $i -le 3 ]]; then
      $work_dir/agg.zsh \
        -a "(?<=Abort Cycles \(%\)\s{6})[\d\.]+" \
        "amplxe-cl -c tsx-exploration -r ${tsx_dir}.vtune/$i/$j/\$i `eval echo $command` > $tsx_dir/$i/$j" \
        "$tsx_dir/$i/$j" \
        "^[\d\.]+" > $tsx_dir/$i/_$j
    fi
  done
done