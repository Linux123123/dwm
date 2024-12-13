#!/bin/bash

/home/linux123123/.fehbg &
numlockx on &
dwmblocks &
nm-applet &
dunst &
copyq --start-server &
flameshot &
thunar --daemon &
blueman-applet &
birdtray &

/usr/lib/polkit-kde-authentication-agent-1 &

eval $(ssh-agent)
export SSH_AUTH_SOCK
