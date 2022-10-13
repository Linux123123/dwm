#!/bin/bash

/home/linux123123/.fehbg &
numlockx on &
dwmblocks &
nm-applet &
armcord &
youtube-music &
nextcloud --background &
dunst &
copyq &
flameshot &
thunar --daemon &
birdtray &

eval "$(gnome-keyring-daemon --start)"
export SSH_AUTH_SOCK
polkit-dumb-agent &
blueman-applet &
/home/linux123123/.local/bin/hyperion-x11 -a 192.168.0.131:19400 -s 25 &
