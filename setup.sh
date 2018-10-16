# My strategy here is to just link the config files into
# the default locations they are expected to be at and if I edit them,
# this git repo will be dirty

I3_DIR=~/.config/i3/
mkdir -p "$I3_DIR"

ln zshrc ~/.zshrc
ln zshrc.local ~/.config/
ln fzf.zsh ~/.config/fzf.zsh
ln shell_clipboard_sync.zsh ~/.config/

ln i3/config "$I3_DIR"/
ln i3/i3status.conf "$I3_DIR"/
