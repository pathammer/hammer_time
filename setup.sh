ln zshrc ~/.zshrc
ln zshrc.local ~/.config/
ln fzf.zsh ~/.config/fzf.zsh

I3_DIR=~/.config/i3/
mkdir -p "$I3_DIR"
ln i3/config "$I3_DIR"/
ln i3/i3status.conf "$I3_DIR"/
