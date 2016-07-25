/* ScummVM - Graphic Adventure Engine
*
* ScummVM is the legal property of its developers, whose names
* are too numerous to list here. Please refer to the COPYRIGHT
* file distributed with this source distribution.
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
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*
*/

#ifndef MACVENTURE_GUI_H
#define MACVENTURE_GUI_H

#include "graphics/macgui/macwindowmanager.h"
#include "graphics/macgui/macwindow.h"
#include "graphics/macgui/macmenu.h"

#include "graphics/font.h"

#include "macventure/macventure.h"
#include "macventure/container.h"
#include "macventure/image.h"
#include "macventure/prebuilt_dialogs.h"
#include "macventure/dialog.h"
#include "macventure/controls.h"
#include "macventure/windows.h"

namespace MacVenture {

using namespace Graphics::MacGUIConstants;
using namespace Graphics::MacWindowConstants;
class MacVentureEngine;
typedef uint32 ObjID;

class Cursor;
class ConsoleText;
class CommandButton;
class ImageAsset;
class Dialog;

BorderBounds borderBounds(MVWindowType type);
extern PrebuiltDialog prebuiltDialogs[];

enum MenuAction {
	kMenuActionAbout,
	kMenuActionNew,
	kMenuActionOpen,
	kMenuActionSave,
	kMenuActionSaveAs,
	kMenuActionQuit,
	kMenuActionUndo,
	kMenuActionCut,
	kMenuActionCopy,
	kMenuActionPaste,
	kMenuActionClear,
	kMenuActionCleanUp,
	kMenuActionMessUp,

	kMenuActionCommand
};
//} using namespace MacVentureMenuActions;

struct DraggedObj {
	ObjID id;
	Common::Point pos;
	Common::Point mouseOffset;
	Common::Point startPos;
	WindowReference startWin;
	bool hasMoved;
};

enum CursorState {
	// HACK, I should define a proper FSM for this
	kCursorIdle,
	kCursorSingleClick, // Triggered when mouse goes up
	kCursorSingleClickAwait, // Triggered when we are in single click and mouse goes down
	kCursorSingleClickTrap, // Trap state, for when we are in await, and the timer goes off
	kCursorDoubleClick
};

class Gui {

public:
	Gui(MacVentureEngine *engine, Common::MacResManager *resman);
	~Gui();

	void draw();
	void drawMenu();
	void drawTitle();

	void clearControls();
	bool processEvent(Common::Event &event);
	void handleMenuAction(MenuAction action);
	void updateWindow(WindowReference winID, bool containerOpen);
	void invertWindowColors(WindowReference winID);


	WindowReference createInventoryWindow(ObjID objRef);
	bool tryCloseWindow(WindowReference winID);

	Common::Point getObjMeasures(ObjID obj);

	WindowReference getObjWindow(ObjID objID);
	WindowReference findObjWindow(ObjID objID);

	// Event processors
	bool processCommandEvents(WindowClick click, Common::Event &event);
	bool processMainGameEvents(WindowClick click, Common::Event &event);
	bool processOutConsoleEvents(WindowClick click, Common::Event &event);
	bool processSelfEvents(WindowClick click, Common::Event &event);
	bool processExitsEvents(WindowClick click, Common::Event &event);
	bool processDiplomaEvents(WindowClick click, Common::Event &event);
	bool processInventoryEvents(WindowClick click, Common::Event &event);

	void processCursorTick();

	const WindowData& getWindowData(WindowReference reference);

	const Graphics::Font& getCurrentFont();

	// Clicks
	void handleSingleClick(Common::Point pos);
	void handleDoubleClick(Common::Point pos);

	// Modifiers
	void bringToFront(WindowReference window);
	void setWindowTitle(WindowReference winID, Common::String string);
	void updateWindowInfo(WindowReference ref, ObjID objID, const Common::Array<ObjID> &children);

	void addChild(WindowReference target, ObjID child);
	void removeChild(WindowReference target, ObjID child);

	void clearExits();
	void unselectExits();
	void updateExit(ObjID id);

	void printText(const Common::String &text);

	//Dialog interactions
	void showPrebuiltDialog(PrebuiltDialogs type);
	bool isDialogOpen();

	void getTextFromUser();
	void setTextInput(Common::String str);
	void closeDialog();

	void loadGame(int slot);
	void saveInto(int slot);


private: // Attributes

	MacVentureEngine *_engine;
	Common::MacResManager *_resourceManager;

	Graphics::ManagedSurface _screen;
	Graphics::MacWindowManager _wm;

	Common::List<WindowData> *_windowData;
	Common::Array<CommandButton> *_controlData;
	Common::Array<CommandButton> *_exitsData;

	Graphics::MacWindow *_controlsWindow;
	Graphics::MacWindow *_mainGameWindow;
	Graphics::MacWindow *_outConsoleWindow;
	Graphics::MacWindow *_selfWindow;
	Graphics::MacWindow *_exitsWindow;
	Graphics::MacWindow *_diplomaWindow;
	Common::Array<Graphics::MacWindow*> _inventoryWindows;
	Graphics::Menu *_menu;
	Dialog *_dialog;

	Container *_graphics;
	Common::HashMap<ObjID, ImageAsset*> _assets;

	Graphics::ManagedSurface _draggedSurface;
	DraggedObj _draggedObj;

	Cursor *_cursor;

	ConsoleText *_consoleText;

private: // Methods

	// Initializers
	void initGUI();
	void initWindows();
	void assignObjReferences(); // Mainly guesswork

	// Loaders
	bool loadMenus();
	bool loadWindows();
	bool loadControls();
	void loadBorder(Graphics::MacWindow * target, Common::String filename, bool active, MVWindowType type);
	void loadGraphics();

	// Drawers
	void drawWindows();
	void drawCommandsWindow();
	void drawMainGameWindow();
	void drawSelfWindow();
	void drawInventories();
	void drawExitsWindow();
	void drawConsoleWindow();

	void drawDraggedObject();
	void drawObjectsInWindow(WindowReference target, Graphics::ManagedSurface *surface);
	void drawWindowTitle(WindowReference target, Graphics::ManagedSurface *surface);
	void drawDialog();

	void moveDraggedObject(Common::Point target);

	// Finders
	WindowReference findWindowAtPoint(Common::Point point);
	Common::Point getWindowSurfacePos(WindowReference reference);
	WindowData& findWindowData(WindowReference reference);
	Graphics::MacWindow *findWindow(WindowReference reference);

	// Utils
	bool canBeSelected(ObjID obj, const Common::Event &event, const Common::Rect &clickRect, WindowReference ref);
	void checkSelect(const WindowData &data, const Common::Event &event, const Common::Rect &clickRect, WindowReference ref);
	bool isRectInsideObject(Common::Rect target, ObjID obj);
	void selectDraggable(ObjID child, WindowReference origin, Common::Point startPos);
	void handleDragRelease(Common::Point pos, bool shiftPressed, bool isDoubleClick);
	Common::Rect calculateClickRect(Common::Point clickPos, Common::Rect windowBounds);
	Common::Point localize(Common::Point point, WindowReference origin, WindowReference target);
	void removeInventoryWindow(WindowReference ref);

	void ensureAssetLoaded(ObjID obj);

};

class Cursor {
enum ClickState {
	kCursorIdle = 0,
	kCursorSC = 1,
	kCursorNoTick = 2,
	kCursorSCTrans = 3,
	kCursorExecSC = 4,
	kCursorExecDC = 5,
	kCursorStateCount
};

enum CursorInput { // Columns for the FSM transition table
	kTickCol = 0,
	kButtonDownCol = 1,
	kButtonUpCol = 2,
	kCursorInputCount
};


ClickState _transitionTable[kCursorStateCount][kCursorInputCount] = {
	/* kCursorIdle */	{kCursorIdle,	kCursorIdle,	kCursorSC		},
	/* kCursorSC */		{kCursorExecSC,	kCursorSCTrans,	kCursorExecDC	},
	/* IgnoreTick */	{kCursorNoTick, kCursorNoTick,	kCursorExecSC	},
	/* SC Transition */	{kCursorNoTick,	kCursorNoTick,	kCursorExecDC	},
	/* Exec SC */		{kCursorIdle,	kCursorExecSC,	kCursorExecSC	},	// Trap state
	/* Exec DC */		{kCursorIdle,	kCursorExecDC,	kCursorExecDC	}	// Trap state
};

public:
	Cursor(Gui *gui) {
		_gui = gui;
		_state = kCursorIdle;
	}

	~Cursor() {}

	void tick() {
		executeState();
		changeState(kTickCol);
	}

	bool processEvent(const Common::Event &event) {

		if (event.type == Common::EVENT_MOUSEMOVE) {
			_pos = event.mouse;
			return true;
		}
		if (event.type == Common::EVENT_LBUTTONDOWN) {
			changeState(kButtonDownCol);
			return true;
		}
		if (event.type == Common::EVENT_LBUTTONUP) {
			changeState(kButtonUpCol);
			return true;
		}

		return false;
	}

	Common::Point getPos() {
		return _pos;
	}

private:

	void changeState(CursorInput input) {
		debug(4, "Change cursor state: [%d] -> [%d]", _state, _transitionTable[_state][input]);
		_state = _transitionTable[_state][input];
	}

	void executeState() {
		if (_state == kCursorExecSC) {
			_gui->handleSingleClick(_pos);
			changeState(kTickCol);
		} else if (_state == kCursorExecDC) {
			_gui->handleDoubleClick(_pos);
			changeState(kTickCol);
		}
	}


private:
	Gui *_gui;

	Common::Point _pos;
	ClickState _state;

};

class ConsoleText {

public:

	ConsoleText(Gui *gui) {
		_gui = gui;
		_lines.push_back("");
	}

	~ConsoleText() {

	}

	void printLine(const Common::String &str, int maxW) {
		Common::StringArray wrappedLines;
		int textW = maxW;
		const Graphics::Font *font = &_gui->getCurrentFont();

		font->wordWrapText(str, textW, wrappedLines);

		if (wrappedLines.empty()) // Sometimes we have empty lines
			_lines.push_back("");

		for (Common::StringArray::const_iterator j = wrappedLines.begin(); j != wrappedLines.end(); ++j)
			_lines.push_back(*j);

		updateScroll();
	}

	void renderInto(Graphics::ManagedSurface *target, uint leftOffset) {
		target->fillRect(target->getBounds(), kColorWhite);
		const Graphics::Font *font = &_gui->getCurrentFont();
		uint y = target->h - font->getFontHeight();
		for (uint i = _lines.size() - 1; i != 0; i--) {
			font->drawString(target, _lines[i], leftOffset, y, font->getStringWidth(_lines[i]), kColorBlack);
			y -= font->getFontHeight();
		}
	}

	void updateScroll() {
		_scrollPos = _lines.size() - 1;
	}

	void scrollDown() {
		if (_scrollPos < _lines.size() - 1) _scrollPos++;
	}

	void scrollUp() {
		debug("scroll up");
		if (_scrollPos > 0) _scrollPos--;
	}


private:

	Gui *_gui;

	Common::StringArray _lines;
	int _scrollPos;

};

} // End of namespace MacVenture

#endif
