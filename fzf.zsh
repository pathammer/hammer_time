# Setup fzf
# ---------
if [[ ! "$PATH" == */home/hammer/code/fzf/bin* ]]; then
  export PATH="$PATH:/home/hammer/code/fzf/bin"
fi

if [[ -n $SSH_CONNECTION ]]; then
  export FZF_DEFAULT_OPTS="--bind='ctrl-o:execute(${EDITOR:-vim} {})+abort'"
else
  export FZF_DEFAULT_OPTS="--bind='ctrl-o:execute(xdg-open {})+abort' --bind='ctrl-e:execute(${EDITOR:-vim} {})+abort'"
fi



export FZF_DEFAULT_COMMAND="find -P * -path '*/\.*' -prune -o -type f -print -o -type l -print 2> /dev/null"

# To apply the command to CTRL-T as well
export FZF_CTRL_T_COMMAND="$FZF_DEFAULT_COMMAND"


# Auto-completion
# ---------------
[[ $- == *i* ]] && source "/home/hammer/code/fzf/shell/completion.zsh" 2> /dev/null

# Key bindings
# ------------
source "/usr/share/doc/fzf/examples/key-bindings.zsh"


# fkill - kill processes - list only the ones you can kill. Modified the earlier script.
fkill() {
    local pid
    if [ "$UID" != "0" ]; then
	pid=$(ps -f -u $UID | sed 1d | fzf -m | awk '{print $2}')
    else
	pid=$(ps -ef | sed 1d | fzf -m | awk '{print $2}')
    fi
    
    if [ "x$pid" != "x" ]
    then
	echo $pid | xargs kill -${1:-9}
    fi
}


# fbr - checkout git branch (including remote branches), sorted by most recent commit, limit 30 last branches
fbr() {
    local branches branch
    branches=$(git for-each-ref --count=30 --sort=-committerdate refs/heads/ --format="%(refname:short)") &&
	branch=$(echo "$branches" |
			fzf-tmux -d $(( 2 + $(wc -l <<< "$branches") )) +m) &&
	git checkout $(echo "$branch" | sed "s/.* //" | sed "s#remotes/[^/]*/##")
}

# fco - checkout git branch/tag
fco() {
    local tags branches target
    tags=$(
	git tag | awk '{print "\x1b[31;1mtag\x1b[m\t" $1}') || return
    branches=$(
	git branch --all | grep -v HEAD             |
	    sed "s/.* //"    | sed "s#remotes/[^/]*/##" |
	    sort -u          | awk '{print "\x1b[34;1mbranch\x1b[m\t" $1}') || return
    target=$(
	(echo "$tags"; echo "$branches") |
	    fzf-tmux -l30 -- --no-hscroll --ansi +m -d "\t" -n 2) || return
    git checkout $(echo "$target" | awk '{print $2}')
}


# fco_preview - checkout git branch/tag, with a preview showing the commits between the tag/branch and HEAD
fco_preview() {
    local tags branches target
    tags=$(
	git tag | awk '{print "\x1b[31;1mtag\x1b[m\t" $1}') || return
    branches=$(
	git branch --all | grep -v HEAD |
	    sed "s/.* //" | sed "s#remotes/[^/]*/##" |
	    sort -u | awk '{print "\x1b[34;1mbranch\x1b[m\t" $1}') || return
    target=$(
	(echo "$tags"; echo "$branches") |
	    fzf --no-hscroll --no-multi --delimiter="\t" -n 2 \
		--ansi --preview="git log -200 --pretty=format:%s $(echo {+2..} |  sed 's/$/../' )" ) || return
    git checkout $(echo "$target" | awk '{print $2}')
}

# flog - git commit browser
flog() {
    git log --graph --color=always \
	--format="%C(auto)%h%d %s %C(black)%C(bold)%cr" "$@" |
	fzf --ansi --no-sort --reverse --tiebreak=index --bind=ctrl-s:toggle-sort \
	          --bind "ctrl-m:execute:
                (grep -o '[a-f0-9]\{7\}' | head -1 |
                xargs -I % sh -c 'git show --color=always % | less -R') << 'FZF-EOF'
                {}
FZF-EOF"
}


# tm - create new tmux session, or switch to existing one. Works from within tmux too. (@bag-man)
# `tm` will allow you to select your tmux session via fzf.
# `tm irc` will attach to the irc session (if it exists), else it will create it.

tm() {
    [[ -n "$TMUX" ]] && change="switch-client" || change="attach-session"
    if [ $1 ]; then
	tmux $change -t "$1" 2>/dev/null || (tmux new-session -d -s $1 && tmux $change -t "$1"); return
    fi
    session=$(tmux list-sessions -F "#{session_name}" 2>/dev/null | fzf --exit-0) &&  tmux $change -t "$session" || echo "No sessions found."
}

alias preview="fzf --preview 'bat --color \"always\" {}'"
