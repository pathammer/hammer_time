#!/bin/zsh

#copyq add "test" "one" "two\ntwo" "three\nthree"

CLIP=()
#CLIP+=("$(copyq clipboard  | tr '\r\n' '\r')")

for n ({0..25});
do
    CLIP+=("$(copyq read $n | tr '\r\n' '\r' )")
done

CONCAT=""
for i in ${(u)CLIP[@]}; do # remove duplicates
    temp=$(echo $i | xargs)
    CONCAT="$CONCAT\n$temp"
done

CONCAT=${CONCAT:2} # remove the leading newline char \n

SELECTION=$(echo $CONCAT | dmenu -i -l 25 | tr '\r' '\r\n')

if [ ! -z "$SELECTION" ]; then
    echo -n "$SELECTION" | xclip -i -selection XA_CLIPBOARD    
fi;
