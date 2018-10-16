#!/bin/zsh

#copyq add "test" "one" "two\ntwo" "three\nthree"

CLIP=$(copyq clipboard  | tr '\r\n' '\r')

for n ({0..10});
do
    CLIP="$CLIP\n$(copyq read $n | tr '\r\n' '\r' )"
done
SELECTION=$(echo $CLIP | dmenu -i -l 20 | tr '\r' '\r\n')

if [ ! -z "$SELECTION" ]; then
    copyq copy "$SELECTION"
fi;
