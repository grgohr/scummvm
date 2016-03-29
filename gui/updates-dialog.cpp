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
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "common/str.h"
#include "common/system.h"
#include "common/translation.h"
#include "gui/updates-dialog.h"
#include "gui/gui-manager.h"
#include "gui/ThemeEval.h"
#include "gui/widget.h"

namespace GUI {

enum {
	kOkCmd = 'OK  ',
	kCancelCmd = 'CNCL'
};


UpdatesDialog::UpdatesDialog() : Dialog(30, 20, 260, 124) {

	const int screenW = g_system->getOverlayWidth();
	const int screenH = g_system->getOverlayHeight();

	int buttonWidth = g_gui.xmlEval()->getVar("Globals.Button.Width", 0);
	int buttonHeight = g_gui.xmlEval()->getVar("Globals.Button.Height", 0);

	const char *message = _(
		"ScummVM now supports automatic check for updates\n"
		"which requires access to the Internet.\n"
  		"\n"
		"Would you like to enable this feature?\n"
	    "(You can always enable it in the options\n"
		"dialog on the Misc tab)");

	// First, determine the size the dialog needs. For this we have to break
	// down the string into lines, and taking the maximum of their widths.
	// Using this, and accounting for the space the button(s) need, we can set
	// the real size of the dialog
	Common::Array<Common::String> lines;
	int lineCount, okButtonPos, cancelButtonPos;
	int maxlineWidth = g_gui.getFont().wordWrapText(message, screenW - 2 * 20, lines);

	_w = MAX(maxlineWidth, (2 * buttonWidth) + 10) + 20;

	lineCount = lines.size();

	_h = 16;
	_h += buttonHeight + 8;

	_h += lineCount * kLineHeight;

	// Center the dialog
	_x = (screenW - _w) / 2;
	_y = (screenH - _h) / 2;

	// Each line is represented by one static text item.
	int y = 10;
	for (int i = 0; i < lines.size(); i++) {
		new StaticTextWidget(this, 10, y, maxlineWidth, kLineHeight,
								lines[i], Graphics::kTextAlignCenter);
		y += kLineHeight;
	}

	okButtonPos = (_w - (buttonWidth * 2)) / 2;
	cancelButtonPos = ((_w - (buttonWidth * 2)) / 2) + buttonWidth + 10;

	new ButtonWidget(this, okButtonPos, _h - buttonHeight - 8, buttonWidth, buttonHeight, "OK", 0, kOkCmd, Common::ASCII_RETURN);	// Confirm dialog
	new ButtonWidget(this, cancelButtonPos, _h - buttonHeight - 8, buttonWidth, buttonHeight, "Cancel", 0, kCancelCmd, Common::ASCII_ESCAPE);	// Cancel dialog
}

void UpdatesDialog::handleCommand(CommandSender *sender, uint32 cmd, uint32 data) {
	if (cmd == kOkCmd) {
		close();
	} else if (cmd == kCancelCmd) {
		close();
	} else {
		Dialog::handleCommand(sender, cmd, data);
	}
}

} // End of namespace GUI
