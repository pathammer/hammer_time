#!/bin/bash

set -e
i3-msg 'workspace 1: comms; append_layout /home/hammer/.config/i3/comms.json'
slack &
hiri &
