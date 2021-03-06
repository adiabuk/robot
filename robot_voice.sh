#!/usr/bin/env bash

# Small shell script to generate robot voice, for microSD card


echo $@ | espeak --stdout -v female2 | play -t wav - \
overdrive 10 \
echo 0.8 0.8 5 0.7 \
echo 0.8 0.7 3 0.7 \
echo 0.8 0.7 10 0.7 \
echo 0.8 0.7 12 0.7 \
echo 0.8 0.88 12 0.7 \
echo 0.8 0.88 30 0.7 \
echo 0.6 0.6 60 0.7 \
gain 8

