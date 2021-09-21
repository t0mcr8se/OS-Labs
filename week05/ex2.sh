#!/bin/bash

if [[ ! -f "file.txt" ]]; then
    echo "1" > "file.txt"
fi

while true; do
    if ln "file.txt" "file.txt.lock" > /dev/null 2>&1 ; then
        n=$(cat "file.txt" | tail -n 1)
        echo "$((n + 1))" >> nums.txt
        rm "file.txt.lock"
    fi
done
