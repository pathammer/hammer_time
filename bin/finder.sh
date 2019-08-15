#!/bin/bash
# a script to open favorite files in nautalus
declare -A arr
recent=$(head -n 1 ~/.zdirs | cut -d'/' -f4-)
arr+=(
    [home]="/home/hammer/"
    [downloads]="/home/hammer/Downloads"
    [downloads]="/home/hammer/Downloads"
    [firefox_business_downloads]="/home/hammer/snap/firefox/common/Downloads/"
    [firefox_personal]="/home/hammer/snap/firefox/common/Downloads/"
    [code]="/home/hammer/code/"
    [tmp]="/tmp"
    [$recent]="$recent"
)

choice=$(printf "%s\n" "${!arr[@]}" | dmenu -l 20)
echo opening  ${arr[$choice]}
# Execute choice if dmenu returns ok:
[ $? = 0 ] && xdg-open ${arr[$choice]}

