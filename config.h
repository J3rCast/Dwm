/* See LICENSE file for copyright and license details. */

/* APPAREANCE */
// border pixel of windows
static const unsigned int borderpx  = 1;
// gaps between windows
static const unsigned int gappx     = 7;
// snap pixel
static const unsigned int snap      = 32;
// 0 means no bar
static const int showbar            = 1;
// 0 means bottom bar
static const int topbar             = 1;
// 0 means no focus when cursor is on a window
static const int focusonwheel       = 0;

// ------------------------------ FONTS  --------------------------------

static const char *fonts[]          = { "UbuntuMono:size=12.5:antialias=true:autohint:true", "CodeNewRoman Nerd Font:pixelsize=14"};

// ------------------------------ COLORS ----------------------------------
struct Theme {
    char *inactive;
    char *active;
    char *bg;
    char *focus;
};

static const struct Theme material = {
    .inactive = "#4c566a",
    .active = "#ffffff",
    .bg = "#0f101a",
    .focus = "#a151d3"
};

static const struct Theme onedark = {
    .inactive = "#4c566a",
    .active = "#ffffff",
    .bg = "#1e2127",
    .focus = "#E06C75"
};

static const struct Theme monokai_pro = {
    .inactive = "#727072",
    .active = "#2d2a2e",
    .bg = "#2d2a2e",
    .focus = "#a9dc76"
};

static const struct Theme nord = {
    .inactive = "#4c566a",
    .active = "#ffffff",
    .bg = "#2e3440",
    .focus = "#81a1c1"
};

static const char window_border[] = "#000000";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	{ material.inactive, material.bg, window_border },
    	{ material.active, material.focus,  material.focus  },

    	{ onedark.inactive, onedark.bg, window_border },
    	{ onedark.active, onedark.focus,  onedark.focus  },
	
    	{ nord.inactive, nord.bg, window_border },
    	{ nord.active, nord.focus,  nord.focus  },

    	{ monokai_pro.inactive, monokai_pro.bg, window_border },
    	{ monokai_pro.active, monokai_pro.focus,  monokai_pro.focus },
};

// ----------------------------- AUTOSTART APPS --------------------------

static const char *const autostart[] = {
	/*starts the script for the status bar*/
	"sh", "-c", "~/.config/dwm/date", NULL,
	/*starts feh, for the background*/
	"sh", "-c", "feh --bg-fill --randomize /home/jerson/Desktop/backgrounds/*", NULL,
	/*starts compton as compositor*/
	"sh", "-c", "compton", NULL,
	NULL /* terminate */
};

// ------------------------------ TAGS -----------------------------------
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Slack",     NULL,       NULL,      1 << 2,       0,           0 },
	{ "Zoom",      NULL,       NULL,      0,            1,           1 },
};

//--------------------------------- LAYOUTS ------------------------------
static const float mfact     = 0.55;
static const int nmaster     = 1;
static const int resizehints = 1;

static const Layout layouts[] = {
	 /*symbol     arrange function */
	{ "TL",      tile },    /* first entry is default */
	{ "Float",      NULL },   /* no layout function means floating behavior */
	{ "FS",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// ---------------------------- COMMANDS -------------------------------
static const char *termcmd[]  = { "alacritty", NULL };
static const char *firef[] = {"firefox", NULL};
static const char *slack[] = {"slack", NULL};
static const char *zoomapp[] = {"zoom", NULL};
static const char *ShutDown[] = {"shutdown", "-h", "now", NULL};
static const char *rofiApp[] = {"rofi", "-show", "run", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */

	/*WINDOWS CONTROL*/
	{ MODKEY|ShiftMask,             XK_f,      togglefloating, {0} },

	/* SPAWN APPS */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_f,      spawn,          {.v = firef } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = slack } },
	{ MODKEY|ShiftMask,             XK_z,      spawn,          {.v = zoomapp } },
	{ MODKEY,                       XK_r,      spawn,          {.v = rofiApp } },

	/* HIDE BAR */
	{ MODKEY,                       XK_b,      togglebar,      {0} },

	/* CHANGE WINDOW FOCUS */
	{ MODKEY,                       XK_l,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_h,      focusstack,     {.i = -1 } },

	/* RESIZE WINDOW */
	{ MODKEY|ShiftMask,              XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,              XK_l,      setmfact,       {.f = +0.05} },

	/* CLOSE WINDOW */
	{ MODKEY, 	                XK_p,      killclient,     {0} },

	/* MONITOR FOCUS & WINDOW SWAP BETWEEN THEM */
	{ MODKEY,                       XK_space,  focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_space,  tagmon,         {.i = -1 } },

	/* NEXT/PREV TAG */
	{ MODKEY,                       XK_n,      viewnext,       {0} },
	{ MODKEY,                       XK_v,      viewprev,       {0} },
	{ MODKEY|ShiftMask,             XK_n,      tagtonext,      {0} },
	{ MODKEY|ShiftMask,             XK_v,      tagtoprev,      {0} },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	/*LAYOUT CONTROL*/
	{ MODKEY|ControlMask,           XK_l,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ControlMask,           XK_y,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_f,      setlayout,      {.v = &layouts[2]} },

	/* QUIT MODKEYS */
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} }, 
	{ MODKEY|ShiftMask,             XK_t,      spawn,          {.v = ShutDown } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

/*----------------------UNUSEDMODKEYS------------------------*/
/*	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,                       XK_f, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },*/
