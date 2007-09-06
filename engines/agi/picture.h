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
 * $URL$
 * $Id$
 *
 */

#ifndef AGI_PICTURE_H
#define AGI_PICTURE_H

#include "agi/agi.h"

namespace Agi {

#define _DEFAULT_WIDTH		160
#define _DEFAULT_HEIGHT		168

/**
 * AGI picture resource.
 */
struct AgiPicture {
	uint32 flen;			/**< size of raw data */
	uint8 *rdata;			/**< raw vector image data */
};

// AGI picture version
enum AgiPictureVersion {
	AGIPIC_C64,
	AGIPIC_V1,
	AGIPIC_V15,
	AGIPIC_V2
};

enum AgiPictureFlags {
	kPicFNone,
	kPicFCircle,
	kPicFStep
};

class AgiBase;
class GfxMgr;

class PictureMgr {
	AgiBase *_vm;
	GfxMgr *_gfx;

private:

	void drawLine(int x1, int y1, int x2, int y2);
	void putVirtPixel(int x, int y);
	void dynamicDrawLine();
	void absoluteDrawLine();
	INLINE int isOkFillHere(int x, int y);
	void fillScanline(int x, int y);
	void agiFill(unsigned int x, unsigned int y);
	void xCorner();
	void yCorner();
	void fill();
	int plotPatternPoint(int x, int y, int bitpos);
	void plotBrush();

	uint8 nextByte() { return _data[_foffs++]; }

public:
	PictureMgr(AgiBase *agi, GfxMgr *gfx);

	int decodePicture(int n, int clear, bool agi256 = false, int pic_width = _DEFAULT_WIDTH, int pic_height = _DEFAULT_HEIGHT);
	int unloadPicture(int);
	void drawPicture();
	void showPic(int x = 0, int y = 0, int pic_width = _DEFAULT_WIDTH, int pic_height = _DEFAULT_HEIGHT);
	uint8 *convertV3Pic(uint8 *src, uint32 len);

	void plotPattern(int x, int y);		// public because it's used directly by preagi

	void setPattern(uint8 code, uint8 num);

	void setPictureType(int type);
	void setPictureData(uint8 *data, int len);

	void setPictureFlags(int flags) { _flags = flags; }

	void setOffset(int offX, int offY) {
		_xOffset = offX;
		_yOffset = offY;
	}

private:
	uint8 *_data;
	uint32 _flen;
	uint32 _foffs;

	uint8 _patCode;
	uint8 _patNum;
	uint8 _priOn;
	uint8 _scrOn;
	uint8 _scrColor;
	uint8 _priColor;

	uint8 _minCommand;

	int _pictureType;
	int _width, _height;
	int _xOffset, _yOffset;

	int _flags;
};

} // End of namespace Agi

#endif /* AGI_PICTURE_H */
