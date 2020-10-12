#!/bin/bash

if [[ -n $(pidof $1) ]]; then
    python3 ~/bin/nextmatch.py $1
else
	$1
fi
