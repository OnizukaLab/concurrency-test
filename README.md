# concurrency-test

## About this command

### Argments

|index|arg|default by tester|
|---|---|---|
|1|type of concurrency|NaN|
|2|num of iterations|1000000|
|3|concurrency|num of physical cores|
|4|load|1000|
|5|conflict rate(length of array)|1000|
|6|element size(density of array)|8|
|7|chunk size|8|
|8|write op rate|0.2|

## Usage

### Prerequisites

``` shell
sudo dnf install cmake gcc gcc-c++ libitm kernel-devel zsh perf
# install vtune
# build vtune drivers
# install vtune drivers
```

### Measurement

``` shell
source /path/to/vtune/amplxe-vars.sh
cd /path/to/concurrency-test
cmake .
make
for s in tester/*.zsh; do; ./$s; done; # all measurement
tester/conc.zsh 1 6 # or customized one (concurrency/mutex&atomic)
```

and then

#### Elapsed time

``` shell
for i in {0..6}; do; cat result/*/*/ahs/$i | grep -oP "^\d+(\.\d+)?"; echo ""; done;
```

#### Abort rate

``` shell
for i in {2..5}; do; cat result/*/*/tsx/$i | grep -oP "(?<=Abort Cycles \(%\)\s{6})\d+(\.\d+)?"; echo ""; done;
```

#### Miss rate of all cache

``` shell
for i in {0..6}; do; cat result/*/*/cache/$i | grep -oP "\d+(\.\d+)?(?=\s% of all cache refs)"; echo ""; done;
```
