#!/usr/bin/zsh
for i in {0..6}; do;
  mkdir -p ../result/len/cache/$i
  for ((j = 10; j <= 10000; j *= 10)); do;
    perf stat -e cache-misses,cache-references,L1-dcache-loads,L1-dcache-load-misses \
      ../concurrency-test $i 1000000 64 1000 $j 8 8 0.2 > ../result/len/cache/$i/$j 2>&1
    amplxe-cl -r=../result/len/ahs/$i/$j -c advanced-hotspots ../concurrency-test $i 1000000 64 1000 $j 8 8 0.2
    if [[ $i -eq 2 || $i -eq 3 || $i -eq 4 ]]; then;
      amplxe-cl -r=../result/len/tsx/$i/$j -c tsx-exploration ../concurrency-test $i 1000000 64 1000 $j 8 8 0.2
    fi;
  done;
done;
