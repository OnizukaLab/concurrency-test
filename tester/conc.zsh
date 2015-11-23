#!/usr/bin/zsh
for i in {0..6}; do;
  for ((j = 2; j <= 128; j *= 2)); do;
    for k in {$j..143}; do; echo 0 > /sys/devices/system/cpu/cpu$k/online; done;
    mkdir -p ../result/conc/cache/$i
    perf stat -e cache-misses,cache-references,L1-dcache-loads,L1-dcache-load-misses \
      ../concurrency-test $i 1000000 $j 1000 1000 8 8 0.2 > ../result/conc/cache/$i/$j 2>&1
    amplxe-cl -r=../result/conc/ahs/$i/$j -c advanced-hotspots ../concurrency-test $i 1000000 $j 1000 1000 8 8 0.2
    if [[ $i -eq 2 || $i -eq 3 || $i -eq 4 ]]; then;
      amplxe-cl -r=../result/conc/tsx/$i/$j -c tsx-exploration ../concurrency-test $i 1000000 $j 1000 1000 8 8 0.2
    fi;
    for k in {1..143}; do; echo 1 > /sys/devices/system/cpu/cpu$k/online; done;
  done;
done;
