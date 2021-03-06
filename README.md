# concurrency-test

## About this command

### Arguments

|index|arg|default by tester|
|---|---|---|
|1|a type of concurrency|NaN|
|2|num of iterations|1000000|
|3|concurrency|num of physical cores|
|4|load|1000|
|5|load balance(inside load rate)|0.5|
|6|conflict rate(length of array)|1000|
|7|element size(density of array)|8|
|8|chunk size|8|
|9|write op rate|0.2|

### Types of concurrency

|index|type|
|---|---|
|0|HLE|
|1|RTM|
|2|transaction_atomic(by gcc)|
|3|transaction_relaxed(by gcc)|
|4|mutex lock|
|5|atomic value|
|6|no control|


## Usage

### Prerequisites

``` shell
sudo dnf install cmake gcc gcc-c++ libitm kernel-devel zsh perf
# install vtune, build and install vtune drivers (measuring HTM is depend on vtune, optional)
```

### Measurement

``` shell
cd /path/to/concurrency-test
cmake .
make
source /path/to/vtune/amplxe-vars.sh (optional)
export LANG=C
for s in tester/*.zsh; do ./$s nyan; done # all measurement (save to nyan)
tester/conc.zsh nyan 0 4 # or customized one (concurrency/HLE&mutex, save to nyan)
```

and then

#### Elapsed time

``` shell
for i in {0..6}; do cat result/*/*/time/$i/_*; done
```

#### Abort rate

``` shell
for i in {0..3}; do cat result/*/*/tsx/$i/_* | cut -d ' ' -f 2; done
```

#### Miss rate of all cache

``` shell
for i in {0..6}; do cat result/*/*/cache/$i/_* | cut -d ' ' -f 2; done
```
