#!/bin/bash

#shell function demo
 function func {
    echo "Step 2 "
    return
 }

 echo "Step 1"
 func
 echo "Step 3"

x=5
if [ $x = 5 ]; then
    echo "x equals 5."
else
    echo "x does not equal 5."
fi
