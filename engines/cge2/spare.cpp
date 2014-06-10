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

/*
 * This code is based on original Sfinx source code
 * Copyright (c) 1994-1997 Janus B. Wisniewski and L.K. Avalon
 */

#include "cge2/spare.h"

namespace CGE2 {

void Spare::synchronize() {
	warning("STUB: Spare::Load");
}

void Spare::clear() {
	_container.clear();
}

Sprite *Spare::locate(int ref) {
	for (uint i = 0; i < _container.size(); ++i) {
		if (_container[i]->_ref == ref)
			return _container[i];
	}
	return nullptr;
}

Sprite *Spare::take(int ref) {
	Sprite *spr = nullptr;
	if ((spr = locate(ref)) != nullptr) {
		for (uint i = 0; i < _container.size(); ++i) {
			if (spr == _container[i]) {
				_container.remove_at(i);
				break;
			}
		}
	}
	return spr;
}

void Spare::takeCave(int cav) {
	int bakRef = cav << 8;
	Common::Array<Sprite*> tempCont = _container;
	for (uint i = 0; i < tempCont.size(); ++i) {
		Sprite *spr = tempCont[i];
		int c = spr->_scene;
		if ((c == _vm->_now || c == 0) && spr->_ref != bakRef) {
			spr = take(spr->_ref);
			_vm->_vga->_showQ->insert(spr);
		}
	}
}

void Spare::store(Sprite *spr) {
	_container.insert_at(_container.size(), spr);
}

void Spare::update(Sprite *spr) {
	Sprite *sp = locate(spr->_ref);
	if (sp == nullptr)
		store(spr);
	else
		*sp = *spr;
}

void Spare::dispose(Sprite *spr) {
	if (spr) {
		_vm->_vga->_showQ->remove(spr);
		update(spr->contract());
		if (!_vm->isHero(spr)) {
			for (uint i = 0; i < _container.size(); ++i) {
				if (spr == _container[i]) {
					_container.remove_at(i);
					delete spr;
					spr = nullptr;
					break;
				}
			}
		}
	}
}

void Spare::dispose(int ref) {
	dispose(_vm->_vga->_showQ->locate(ref));
}

void Spare::dispose() {
	for (uint i = 0; i < _container.size(); ++i) {
		if (_container[i]->_ref > 255)
			dispose(_container[i]);
	}
}

} // End of namespace CGE2
