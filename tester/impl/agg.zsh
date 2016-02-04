#!/bin/zsh

zparseopts -D -A opts -- i: -iters:=i o: -outliers:=o p: -parallel=p a+: -additional-regex:=a
niters=5
noutliers=1
regexs=("$3")
local -A opts
if [[ -n "${opts[(i)-i]}" ]]; then
  niters=${opts[-i]}
fi
if [[ -n "${opts[(i)-o]}" ]]; then
  noutliers=${opts[-o]}
fi
if [[ -n "${opts[(i)-p]}" ]]; then
  echo "\"parallel\" option is not implemented"
fi
if [[ -n "${opts[(i)-a]}" ]]; then
  arr=(`echo ${opts[-a]}`)
  regexs+="${arr[@]}"
fi

# assert
if [[ $(($noutliers * 2)) -ge $niters ]]; then
  echo "too many #outliers" 1>&2
  exit 1
fi

# exec and grep each result
# TODO: use GNU parallel
file=`basename $2`
dir=`dirname $2`/___$file
mkdir -p $dir
local -A data
data=()
for i in {1..$niters}; do
  eval $1
  mv $2 $dir/$i
  for r in "${regexs[@]}"; do
    if [[ -n ${data[$i]} ]]; then
      data[$i]="${data[$i]} `cat $dir/$i | grep -oP \"$r\"`"
    else
      data[$i]="${data[$i]}`cat $dir/$i | grep -oP \"$r\"`"
    fi
  done
done
mv "$dir" "$2"
dir="$2"

# remove outliers
for i in {1..$noutliers}; do
  # ($index $first $second ...) per line
  min_idx=`for k in ${(k)data}; do echo "$k $data[$k]"; done | sort -nk2 | head -1 | cut -d ' ' -f 1`
  unset "data[${min_idx}]"
  mv $dir/${min_idx} $dir/_${min_idx}
  max_idx=`for k in ${(k)data}; do echo "$k $data[$k]"; done | sort -rnk2 | head -1 | cut -d ' ' -f 1`
  unset "data[${max_idx}]"
  mv $dir/${max_idx} $dir/_${max_idx}
done

# fold
accs=()
for i in {1..${#regexs[*]}}; do
  accs+=(0.0)
done
for ds in "${data[@]}"; do
  arr=(`echo $ds`)
  c=1
  for d in "${arr[@]}"; do
    accs[$c]=$((${accs[$c]} + d))
    c=$((c + 1))
  done
done

# calc average
avgs=()
c=1
for d in "${accs[@]}"; do
  avgs+=($((1.0 * ${accs[$c]} / ${#data[*]})))
  c=$((c + 1))
done

echo $avgs
