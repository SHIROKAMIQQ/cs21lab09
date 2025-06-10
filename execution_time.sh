#!/bin/bash

if [ "$#" -ne 1 ]; then
  echo "Usage: $0 ./program"
  exit 1
fi

CMD=$1
runs=10
total=0

for ((i=1; i<=runs; i++))
do
    echo "Run $i:"

    TIMEFORMAT=%R
    output=$({ time $CMD > /dev/stdout; } 2>&1)

    approx=$(echo "$output" | head -n -1)
    time_sec=$(echo "$output" | tail -n 1)

    echo "Appr: $approx"
    echo "Time: $time_sec seconds"
    echo ""

    total=$(awk "BEGIN {print $total + $time_sec}")
done

average=$(awk "BEGIN {print $total / $runs}")

echo "Average runtime over $runs runs: $average seconds"
