#!/usr/bin/zsh
suffix=`date +%s`
nprocessor=`lscpu | grep -oP "^Core\(s\) per socket:\s+\d+" | sed -r "s/.+([0-9]+)/\1/"`
nsocket=`lscpu | grep -oP "^Socket\(s\):\s+\d+" | sed -r "s/.+([0-9]+)/\1/"`
ncores=$(( $nprocessor * $nsocket ))

for i in {0..6}; do;
  for ((j = 1; j <= $ncores; j++)); do;
    mkdir -p ../result/conc/{cache,ahs,tsx}
    perf stat -e cache-misses,cache-references,L1-dcache-loads,L1-dcache-load-misses \
      ../concurrency-test $i 1000000 $j 1000 1000 8 8 0.2 >> ../result/conc/cache/$i.$suffix 2>&1
    amplxe-cl -r=../result/conc/cellar/ahs/$i/$j -c advanced-hotspots ../concurrency-test $i 1000000 $j 1000 1000 8 8 0.2 \
      >> ../result/conc/ahs/$i.$suffix
    if [[ $i -eq 2 || $i -eq 3 || $i -eq 4 ]]; then;
      amplxe-cl -r=../result/conc/cellar/tsx/$i/$j -c tsx-exploration ../concurrency-test $i 1000000 $j 1000 1000 8 8 0.2 \
        >> ../result/conc/tsx/$i.$suffix
    fi;
  done;
done;
