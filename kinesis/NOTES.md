My kinesis advantage notes
==========================

Things to try:
✅Need to map left meta key to alt as right now I have no way of typing alt-enter
Need to setup more KC_trans keys to allow layers to inherit from layer below
Potentially move layer 1 wasd gaming layer 10 or something so more sensible layers can inherit from layer 0
My Caps lock tap dance only disables caps when I lift, not after double press and hold. Tried also mapping to double press and it didn't work 😥

trigger a tap dance with the `\|` key which is seldom used
✅ trigger a tap dance with '-_' key so I can type underscore without shift

[windows hyper key fix](https://www.howtogeek.com/445318/how-to-remap-the-office-key-on-your-keyboard/)
tldr; `REG ADD HKCU\Software\Classes\ms-officeapp\Shell\Open\Command /t REG_SZ /d rundll32`

backspace where caps lock is normally

I mapped fn-backspace to delete which is quite common. Now I need to decide what to do about the physical delete key

✅Try [`caps_word`](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_caps_word.md)

I should also find a better use of the physical ctrl and alt keys now that ctrl and alt are under backspace and enter dual function keys.

can I copy where other keyboards (moonlander) put the kp-layer shift buttons?
 * they put layer 1 shift under the left shift key, there's no key there on kinesis
 * they put layer 2 shift under semicolon key (that's forward slach /)

perhaps I can remap my right control key to meh, and use a press and hold right control key elsewhere (pinkey finger backslash is normal)

I should change nextmatch.py to have a version that only searches the current workspace.

