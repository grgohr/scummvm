/* ScummVM - Scumm Interpreter
 * Copyright (C) 2001  Ludvig Strigeus
 * Copyright (C) 2001/2002 The ScummVM project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header$
 *
 */


#include "stdafx.h"
#include "scumm.h"
#include "intern.h"

void Scumm::setupScummVars()
{
	VAR_KEYPRESS = 0;
	VAR_EGO = 1;
	VAR_CAMERA_POS_X = 2;
	VAR_HAVE_MSG = 3;
	VAR_ROOM = 4;
	VAR_OVERRIDE = 5;
	VAR_MACHINE_SPEED = 6;
	VAR_ME = 7;
	VAR_NUM_ACTOR = 8;
	VAR_CURRENT_LIGHTS = 9;
	VAR_CURRENTDRIVE = 10;
	VAR_TMR_1 = 11;
	VAR_TMR_2 = 12;
	VAR_TMR_3 = 13;
	VAR_MUSIC_FLAG = 14;
	VAR_ACTOR_RANGE_MIN = 15;
	VAR_ACTOR_RANGE_MAX = 16;
	VAR_CAMERA_MIN_X = 17;
	VAR_CAMERA_MAX_X = 18;
	VAR_TIMER_NEXT = 19;
	VAR_VIRT_MOUSE_X = 20;
	VAR_VIRT_MOUSE_Y = 21;
	VAR_ROOM_RESOURCE = 22;
	VAR_LAST_SOUND = 23;
	VAR_CUTSCENEEXIT_KEY = 24;
	VAR_TALK_ACTOR = 25;
	VAR_CAMERA_FAST_X = 26;
	VAR_SCROLL_SCRIPT = 27;
	VAR_ENTRY_SCRIPT = 28;
	VAR_ENTRY_SCRIPT2 = 29;
	VAR_EXIT_SCRIPT = 30;
	VAR_EXIT_SCRIPT2 = 31;
	VAR_VERB_SCRIPT = 32;
	VAR_SENTENCE_SCRIPT = 33;
	VAR_HOOK_SCRIPT = 34;
	VAR_CUTSCENE_START_SCRIPT = 35;
	VAR_CUTSCENE_END_SCRIPT = 36;
	VAR_CHARINC = 37;
	VAR_WALKTO_OBJ = 38;
	VAR_DEBUGMODE = 39;
	VAR_HEAPSPACE = 40;
	VAR_RESTART_KEY = 42;
	VAR_PAUSE_KEY = 43;
	VAR_MOUSE_X = 44;
	VAR_MOUSE_Y = 45;
	VAR_TIMER = 46;
	VAR_TMR_4 = 47;
	VAR_SOUNDCARD = 48;
	VAR_VIDEOMODE = 49;
	VAR_SAVELOADDIALOG_KEY = 50;
	VAR_FIXEDDISK = 51;
	VAR_CURSORSTATE = 52;
	VAR_USERPUT = 53;
	VAR_SOUNDRESULT = 56;
	VAR_TALKSTOP_KEY = 57;
	VAR_59 = 59;

	VAR_SOUNDPARAM = 64;
	VAR_SOUNDPARAM2 = 65;
	VAR_SOUNDPARAM3 = 66;
	VAR_MOUSEPRESENT = 67;
	VAR_PERFORMANCE_1 = 68;
	VAR_PERFORMANCE_2 = 69;	// Zak256 Note: Cashcard for Zak
	VAR_ROOM_FLAG = 70;	// Zak256 Note: Cashcard for Annie
	VAR_GAME_LOADED = 71;	// Zak256 Note: Cashcard for Melissa
	VAR_NEW_ROOM = 72;	// Zak256 Note: Cashcard for Leslie
	VAR_VERSION = 75;

	VAR_V5_DRAWFLAGS = 9;
	VAR_MI1_TIMER = 14;

	VAR_V5_OBJECT_LO = 15;
	VAR_V5_OBJECT_HI = 16;

	VAR_V5_TALK_STRING_Y = 54;
	VAR_V5_CHARFLAG = 60;

	VAR_V6_SCREEN_WIDTH = 41;
	VAR_V6_SCREEN_HEIGHT = 54;
	VAR_V6_EMSSPACE = 76;
	VAR_V6_RANDOM_NR = 118;

	VAR_V6_SOUNDMODE = 9;
}


void Scumm_v7::setupScummVars()
{
	VAR_MOUSE_X = 1;
	VAR_MOUSE_Y = 2;
	VAR_VIRT_MOUSE_X = 3;
	VAR_VIRT_MOUSE_Y = 4;
	VAR_V6_SCREEN_WIDTH = 5;
	VAR_V6_SCREEN_HEIGHT = 6;
	VAR_CAMERA_POS_X = 7;
	VAR_CAMERA_POS_Y = 8;
	VAR_OVERRIDE = 9;
	VAR_ROOM = 10;
	VAR_ROOM_RESOURCE = 11;
	VAR_TALK_ACTOR = 12;
	VAR_HAVE_MSG = 13;
	VAR_TIMER = 14;
	VAR_TMR_4 = 15;
	VAR_LEFTBTN_DOWN = 22;
	VAR_RIGHTBTN_DOWN = 23;
	VAR_LEFTBTN_HOLD = 24;
	VAR_RIGHTBTN_HOLD = 25;

	VAR_PERFORMANCE_1 = 26;
	VAR_PERFORMANCE_2 = 27;
	VAR_GAME_LOADED = 29;
	VAR_V6_RANDOM_NR = 34;
	VAR_NEW_ROOM = 35;
	VAR_WALKTO_OBJ = 36;

	VAR_CAMERA_DEST_X = 38;
	VAR_CAMERA_DEST_Y = 39;
	VAR_CAMERA_FOLLOWED_ACTOR = 40;

	VAR_SCROLL_SCRIPT = 50;
	VAR_ENTRY_SCRIPT = 51;
	VAR_ENTRY_SCRIPT2 = 52;
	VAR_EXIT_SCRIPT = 53;
	VAR_EXIT_SCRIPT2 = 54;
	VAR_VERB_SCRIPT = 55;
	VAR_SENTENCE_SCRIPT = 56;
	VAR_HOOK_SCRIPT = 57;
	VAR_CUTSCENE_START_SCRIPT = 58;
	VAR_CUTSCENE_END_SCRIPT = 59;
	VAR_UNK_SCRIPT = 60;
	VAR_UNK_SCRIPT_2 = 61;

	VAR_CUTSCENEEXIT_KEY = 62;
	VAR_RESTART_KEY = 63;			// ???
	VAR_PAUSE_KEY = 64;
	VAR_SAVELOADDIALOG_KEY = 65;	// ???
	VAR_TALKSTOP_KEY = 66;

	VAR_TIMER_NEXT = 97;
	VAR_TMR_1 = 98;
	VAR_TMR_2 = 99;
	VAR_TMR_3 = 100;

	VAR_CAMERA_MIN_X = 101;
	VAR_CAMERA_MAX_X = 102;
	VAR_CAMERA_MIN_Y = 103;
	VAR_CAMERA_MAX_Y = 104;
	VAR_CAMERA_THRESHOLD_X = 105;
	VAR_CAMERA_THRESHOLD_Y = 106;
	VAR_CAMERA_SPEED_X = 107;
	VAR_CAMERA_SPEED_Y = 108;
	VAR_CAMERA_ACCEL_X = 109;
	VAR_CAMERA_ACCEL_Y = 110;

	VAR_EGO = 111;

	VAR_CURSORSTATE = 112;
	VAR_USERPUT = 113;
	VAR_DEFAULT_TALK_DELAY = 114;
	VAR_CHARINC = 115;
	VAR_DEBUGMODE = 116;

	VAR_CHARSET_MASK = 119;
	VAR_VIDEONAME = 123;
	VAR_CUSTOMSCALETABLE = 131;

	//VAR_V5_DRAWFLAGS = 9;
	VAR_MI1_TIMER = 14;
	VAR_V5_OBJECT_LO = 15;
	VAR_V5_OBJECT_HI = 16;
	VAR_V5_TALK_STRING_Y = 54;
	VAR_V5_CHARFLAG = 60;

	VAR_V6_EMSSPACE = 32;
	VAR_STRING2DRAW = 130;
}

void Scumm_v8::setupScummVars()
{
	// VAR_ROOM_HEIGHT = 1;
	// VAR_ROOM_WIDTH = 2;

	VAR_MOUSE_X = 3;
	VAR_MOUSE_Y = 4;
	VAR_VIRT_MOUSE_X = 5;
	VAR_VIRT_MOUSE_Y = 6;

	VAR_CURSORSTATE = 7;
	VAR_USERPUT = 8;

	VAR_CAMERA_POS_X = 9;
	VAR_CAMERA_POS_Y = 10;
	VAR_CAMERA_DEST_X = 11;
	VAR_CAMERA_DEST_Y = 12;
	VAR_CAMERA_FOLLOWED_ACTOR = 13;

	VAR_TALK_ACTOR = 14;
	VAR_HAVE_MSG = 15;
	VAR_MOUSE_BUTTONS = 16;
	VAR_MOUSE_HOLD = 18;

	VAR_TIMEDATE_YEAR = 24;
	VAR_TIMEDATE_MONTH = 25;
	VAR_TIMEDATE_DAY = 26;
	VAR_TIMEDATE_HOUR = 27;
	VAR_TIMEDATE_MINUTE = 28;
	VAR_TIMEDATE_SECOND = 29;

	VAR_OVERRIDE = 30;
	VAR_ROOM = 31;

	//VAR_VOICE_MODE = 39; // 0 is voice, 1 is voice+text, 2 is text only
	VAR_GAME_LOADED = 40;
	VAR_CURRENTDISK = 42;

	VAR_SCROLL_SCRIPT = 50;	// FIXME - guess based on where this is in V7
	VAR_ENTRY_SCRIPT = 51;
	VAR_ENTRY_SCRIPT2 = 52;
	VAR_EXIT_SCRIPT = 53;
	VAR_EXIT_SCRIPT2 = 54;
	VAR_VERB_SCRIPT = 55;
	VAR_SENTENCE_SCRIPT = 56;
	VAR_HOOK_SCRIPT = 57;
	VAR_CUTSCENE_START_SCRIPT = 58;
	VAR_CUTSCENE_END_SCRIPT = 59;

	VAR_CUTSCENEEXIT_KEY = 62;	// FIXME -  guess based on script-1 (could also be 68)

	VAR_PAUSE_KEY = 64;
	VAR_SAVELOADDIALOG_KEY = 65;
	VAR_TALKSTOP_KEY = 67;


	// FIXME - HACK: no clue where these really are located, but we need to put them
	// somewhere so that camera clamping works. So for now just assume they are on their
	// V6 positions (which is somewhat unlikely, considering most stuff moved...)
	VAR_CAMERA_MIN_X = 101;
	VAR_CAMERA_MAX_X = 102;
	VAR_CAMERA_MIN_Y = 103;
	VAR_CAMERA_MAX_Y = 104;
	VAR_CAMERA_THRESHOLD_X = 105;
	VAR_CAMERA_THRESHOLD_Y = 106;
	VAR_CAMERA_SPEED_X = 107;
	VAR_CAMERA_SPEED_Y = 108;
	VAR_CAMERA_ACCEL_X = 109;
	VAR_CAMERA_ACCEL_Y = 110;

	VAR_CUSTOMSCALETABLE = 111;	// FIXME - guess

	VAR_TIMER_NEXT = 112;
	VAR_TMR_1 = 113;
	VAR_TMR_2 = 114;
	VAR_TMR_3 = 115;

	VAR_EGO = 126;

	VAR_DEBUGMODE = 130;
	VAR_KEYPRESS = 132;
	
	VAR_CHARINC = 221;
	
	// var 266, 290 and 301 have something to do with cursor images, since various scripts
	// have setCursorImg(var290,2) or setCursorImg(var266,1) or setCursorImg(var301,1)
}
