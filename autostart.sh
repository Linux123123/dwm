#!/bin/bash

numlockx on &
nitrogen --restore &
dwmblocks &
nm-applet &
polkit-dumb-agent &
discord &
youtube-music &
blueman-applet &
/home/linux123123/.local/bin/hyperion-x11 -a 192.168.0.131:19400 -s 25 &
nextcloud --background &
dunst &
copyq &
flameshot &
thunar --daemon &
birdtray &

eval $(gnome-keyring-daemon --start)
export SSH_AUTH_SOCK