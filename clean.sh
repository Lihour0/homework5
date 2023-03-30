#!/bin/bash
for i in ./*/; 
do
  (cd "$i" && make clean);
done