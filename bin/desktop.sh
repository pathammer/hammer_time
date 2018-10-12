#!/bin/bash

xrandr --auto
xrandr --output DP-6 --primary --rotate left --auto
xrandr --output DP-4 --primary --right-of DP-6 --rotate right  --auto
#xrandr --output HDMI2 --right-of HDMI3 --rotate left --auto
#xrandr --output eDP1 --same-as HDMI3 --auto

xrandr --output DP-0 --right-of DP-4 --rotate left --auto
xrandr --output DP-2.8 --right-of DP-0 --rotate right --auto
