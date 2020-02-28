#!/bin/zsh

#copyq add "test" "one" "two\ntwo" "three\nthree"

CLIP=()
for n ({0..25});
do
    CLIP+=("$(copyq read $n)")
done

CLIP_UNIQ=()
for i in ${(u)CLIP[@]}; do # remove duplicates
    CLIP_UNIQ+="$i"
done

#todo there must be a more clean way to concat, thinking ov using null \000
CONCAT=""
COUNTER=0
for i in ${CLIP_UNIQ[@]}; do # remove duplicates
    temp="$COUNTER $(echo "$i" | head -n 1 | head -c 300)" # only print first line in dmenu
    COUNTER=$((COUNTER+1))
    CONCAT="$CONCAT\n$temp"
done

CONCAT="${CONCAT:2}" # remove the leading newline char \n

SELECTION="$(echo $CONCAT | dmenu -i -l 25)"

if [ ! -z "$SELECTION" ]; then
    IDX=$(echo -n $SELECTION | awk '{ print $1 }')
    CLIP_SEL=${CLIP_UNIQ[$((IDX+1))]} #why do I have to add 1!
    echo -n "$CLIP_SEL" | xargs -0 copyq copy 1>/dev/null
    echo -n "$CLIP_SEL" | xclip -selection XA_CLIPBOARD
fi;
