/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const unsigned int systraypinning =
    1; /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor
          X */
static const unsigned int systrayonleft =
    0;                                        /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int systraypinningfailfirst =
    1;                            /* 1: if pinning fails, display systray on the first monitor, False:
                                     display systray on the last monitor*/
static const int showsystray = 1; /* 0 means no systray */
static const int showbar = 1;     /* 0 means no bar */
static const int topbar = 0;      /* 0 means bottom bar */
static const char *fonts[] = {
    "SauceCodePro Nerd Font "
    "Mono:weight=bold:size=9:antialias=true:hinting=true",
    "Mononoki:size=9:antialias=true:autohint=true",
    "Hack:size=8:antialias=true:autohint=true",
    "JoyPixels:size=10:antialias=true:autohint=true"};

static const char col_1[] = "#282c34"; /* background color of bar */
static const char col_2[] = "#282c34"; /* border color unfocused windows */
static const char col_3[] = "#d7d7d7";
static const char col_4[] =
    "#924441"; /* border color focused windows and tags */

static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_3, col_1, col_2},
    [SchemeSel] = {col_3, col_4, col_4},
};

/* tagging */
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const Rule rules[] = {
    /* class      instance    title       tags mask     isfloating   monitor
     */
    {"dialog", NULL, NULL, 0, 1, -1},
    {"confirm", NULL, NULL, 0, 1, -1},
    {"error", NULL, NULL, 0, 1, -1},
    {"qalculate-gtk", NULL, NULL, 0, 1, -1},
    {"armcord", NULL, NULL, 2, 0, -1},
    {"YouTube Music", NULL, NULL, 2, 0, -1}};

/* layout(s) */
static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
};
static const float mfact = 0.52; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                          \
    {MODKEY, KEY, view, {.ui = 1 << TAG}},                         \
        {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}}, \
        {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},          \
        {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* commands */
static const char *roficmd[] = {"rofi", "-show", "combi", "-show-icons", NULL};
static const char *termcmd[] = {"alacritty", NULL};
static const char *flameshotcmd[] = {"flameshot", "gui", NULL};
static const char *codecmd[] = {"code", NULL};
static const char *browsercmd[] = {"firefox", NULL};
static const char *discordcmd[] = {"armcord", NULL};
static const char *musiccmd[] = {"youtube-music", NULL};
static const char *nextcmd[] = {"playerctl", "next", NULL};
static const char *previouscmd[] = {"playerctl", "previous", NULL};
static const char *stopcmd[] = {"playerctl", "stop", NULL};
static const char *playpausecmd[] = {"playerctl", "play-pause", NULL};
static const char *calculatorcmd[] = {"qalculate-gtk", NULL};

static Key keys[] = {
    /* modifier
                     key        function        argument */
    // MAIN
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = roficmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY | ShiftMask, XK_q, quit, {0}},
    {MODKEY | ShiftMask, XK_r, quit, {1}},

    // APPLICATIONS
    {MODKEY | ShiftMask, XK_s, spawn, {.v = flameshotcmd}},
    {MODKEY | ShiftMask, XK_p, spawn, {.v = codecmd}},
    {MODKEY | ShiftMask, XK_b, spawn, {.v = browsercmd}},
    {MODKEY | ShiftMask, XK_d, spawn, {.v = discordcmd}},
    {MODKEY | ShiftMask, XK_m, spawn, {.v = musiccmd}},

    // Audio
    {0, XF86XK_AudioNext, spawn, {.v = nextcmd}},
    {0, XF86XK_AudioPrev, spawn, {.v = previouscmd}},
    {0, XF86XK_AudioPlay, spawn, {.v = playpausecmd}},
    {0, XF86XK_AudioStop, spawn, {.v = stopcmd}},
    {0, XF86XK_Calculator, spawn, {.v = calculatorcmd}},
    {MODKEY | ShiftMask, XK_Right, spawn, {.v = nextcmd}},
    {MODKEY | ShiftMask, XK_Left, spawn, {.v = previouscmd}},

    // NAVIGATION
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_j, movestack, {.i = +1}},
    {MODKEY | ShiftMask, XK_k, movestack, {.i = -1}},
    {MODKEY, XK_z, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | ShiftMask, XK_c, killclient, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8)};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument
     */
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
