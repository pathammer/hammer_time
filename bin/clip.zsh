#!/bin/zsh

# A script that takes the ouput from copyq, sends it to dmenu for selection, then puts the selection on the top of the clipboard!
# dmenu seems to ignore carrage returns `\r` so I replace newlines with them, then convert back so the newlines in my origional selection
# is preserved. Ugly but works.

# A little control text for testing out the script
#copyq add "test" "one" "two\ntwo" "three\nthree"

CLIP=""

for n ({0..10});
do
    CLIP="$CLIP\n$(copyq read $n | tr '\r\n' '\r')"
done
echo $CLIP | dmenu -i -l 20 | tr '\r' '\r\n' | copyq copy -
