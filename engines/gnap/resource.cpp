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

#include "gnap/resource.h"

namespace Gnap {

// SequenceFrame

void SequenceFrame::loadFromStream(Common::MemoryReadStream &stream) {
	_duration = stream.readUint16LE();
	_isScaled = stream.readUint16LE();
	_rect.left = stream.readUint32LE();
	_rect.top = stream.readUint32LE();
	_rect.right = stream.readUint32LE();
	_rect.bottom = stream.readUint32LE();
	_spriteId = stream.readUint32LE();
	_soundId = stream.readUint32LE();
	_unusedVal = stream.readUint32LE();
	//isScaled = 0;//DEBUG
	debug(1, "SequenceFrame() spriteId: %d; soundId: %d", _spriteId, _soundId);
}

// SequenceAnimation

void SequenceAnimation::loadFromStream(Common::MemoryReadStream &stream) {
	field_0 = stream.readUint16LE();
	field_2 = stream.readUint16LE();
	field_4 = stream.readUint32LE();
	framesCount = stream.readUint16LE();
	field_A = stream.readUint16LE();
	debug(1, "SequenceAnimation() framesCount: %d", framesCount);
	frames = new SequenceFrame[framesCount];
	for (int i = 0; i < framesCount; ++i)
		frames[i].loadFromStream(stream);
}

// SequenceResource

SequenceResource::SequenceResource(int resourceId, byte *data, uint32 size) {
	Common::MemoryReadStream stream(data, size, DisposeAfterUse::NO);
	_field_0 = stream.readUint32LE();
	_sequenceId = stream.readUint32LE();
	_field_8 = stream.readUint32LE();
	_sequenceId2 = stream.readUint32LE();
	_field_10 = stream.readUint32LE();
	_flags = stream.readUint32LE();
	_totalDuration = stream.readUint32LE();
	_xOffs = stream.readUint16LE();
	_yOffs = stream.readUint16LE();
	_animationsCount = stream.readUint32LE();
	_animations = new SequenceAnimation[_animationsCount];
	debug(1, "SequenceResource() _animationsCount: %d", _animationsCount);
	for (int i = 0; i < _animationsCount; ++i) {
		uint32 animationOffs = stream.readUint32LE();
		debug(1, "animationOffs: %08X", animationOffs);
		uint32 oldOffs = stream.pos();
		stream.seek(animationOffs);
		_animations[i].loadFromStream(stream);
		stream.seek(oldOffs);
	}
	// TODO Convert resourceIds
}

SequenceResource::~SequenceResource() {
	delete[] _animations;
}

// SpriteResource

SpriteResource::SpriteResource(int resourceId, byte *data, uint32 size) {
	_data = data;
	_width = READ_LE_UINT16(_data);
	_height = READ_LE_UINT16(_data + 2);
	_unk1 = READ_LE_UINT16(_data + 4);
	_unk2 = READ_LE_UINT16(_data + 6);
	_transparent = READ_LE_UINT16(_data + 8);
	_colorsCount = READ_LE_UINT16(_data + 10);
	_palette = (uint32*)(_data + 12);
	_pixels = _data + 12 + _colorsCount * 4;
	debug(1, "SpriteResource() width: %d; height: %d; colorsCount: %d", _width, _height, _colorsCount);
}

SpriteResource::~SpriteResource() {
	delete[] _data;
}

// SoundResource

SoundResource::SoundResource(int resourceId, byte *data, uint32 size) {
	_data = data;
	_size = size;
}

SoundResource::~SoundResource() {
	delete[] _data;
}

} // End of namespace Gnap
