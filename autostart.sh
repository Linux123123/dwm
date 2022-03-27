#!/bin/bash

nitrogen --restore &

#starting utility applications at boot time
dwmblocks &
nm-applet &
thunar --daemon &
numlockx on &
polkit-dumb-agent & 
dunst &
copyq &
flameshot &
/home/linux123123/.local/bin/hyperion-x11 -a 192.168.0.131:19400 -s 25 &

eval $(gnome-keyring-daemon --start)
export SSH_AUTH_SOCK

discord &
youtube-music &
nextcloud --background &
