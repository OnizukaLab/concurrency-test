#!/usr/bin/zsh
for i in {0..6}; do;
  mkdir -p ../result/ro/cache/$i
  for ((j = 0; j <= 100; j += 20)); do;
    perf stat -e cache-misses,cache-references,L1-dcache-loads,L1-dcache-load-misses \
      ../concurrency-test $i 1000000 64 1000 1000 8 8 $(($j / 100.0)) > ../result/ro/cache/$i/$j 2>&1
    amplxe-cl -r=../result/ro/ahs/$i/$j -c advanced-hotspots ../concurrency-test $i 1000000 64 1000 1000 8 8 $(($j / 100.0))
    if [[ $i -eq 2 || $i -eq 3 || $i -eq 4 ]]; then;
      amplxe-cl -r=../result/ro/tsx/$i/$j -c tsx-exploration ../concurrency-test $i 1000000 64 1000 1000 8 8 $(($j / 100.0))
    fi;
  done;
done;
