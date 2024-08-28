#!/bin/bash

/home/linux123123/.fehbg &
numlockx on &
dwmblocks &
nm-applet &
dunst &
copyq --start-server &
flameshot &
gnome-keyring-daemon --start --components=pkcs11,secrets,ssh &
thunar --daemon &
blueman-applet &
birdtray &

/usr/lib/polkit-kde-authentication-agent-1 &
