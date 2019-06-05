#!/bin/bash

if [ "$EUID" -ne 0 ]
then echo "Please run as root"
     exit
fi

apt get install i3 zsh emacs htop pv nmap tmux tig ncdu tree ranger xdotool screen imagemagick xclip copyq
sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
snap install vlc hiri
snap install --classic slack spotify pycharm-community
snap install intellij-idea-community --classic --edge
pip3 install --user py3status ipython jupyter scipy matplotlib numpy
