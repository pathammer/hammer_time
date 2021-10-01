#!/bin/bash

if [ "$EUID" -ne 0 ]
then echo "Please run as root"
     exit
fi

apt install i3 zsh fzf emacs htop pv nmap tmux tig ncdu tree ranger xdotool screen imagemagick xclip copyq curl playerctl xautolock scrot gthumb autojump prettyping pasystray
sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
chsh hammer -s /usr/bin/zsh
snap install vlc ksnip
snap install --classic slack spotify pycharm-community
snap install intellij-idea-community --classic --edge
pip3 install --user py3status ipython jupyter scipy matplotlib numpy pydbus autotiling
