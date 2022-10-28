Kinesis Keyboard Config
======================

I started using a kint36 keyboard controller which rund qmk firmware. It is a lot more flexable and powerful than the stock kinesis board.

Upload the json layout file to the [qmk configurator](https://config.qmk.fm/#/kinesis/kint36/LAYOUT~). It's easiest to customize the keymap in that graphical online tool. From there, download the new json config layout file and use the qmk tool to translate it to c code `qmk json2c file.json`

Copy that c code into the `keymap.c` file and compile with `qmk compile -kb kinesis/kint36 -km pathammer`

Layer Descriptions
------------------
Layer 0: Base
Layer 1: Left side is WASD gaming layer, Right side is standard Kinesis keypad layer
Layer 2: Left side is debugging F8, F9, F10, F11; Right side is arrow keys mapped to vim keys
Layer 3: Right side mouse controls/media keys
Layer 4: Right side tabbed interface controls