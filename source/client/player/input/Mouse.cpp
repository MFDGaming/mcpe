/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp
	
	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include "Mouse.hpp"

std::vector<MouseAction> Mouse::_inputs;
int Mouse::_index, Mouse::_x, Mouse::_y;
int Mouse::_xOld, Mouse::_yOld, Mouse::_buttonStates[3];

void Mouse::feed(int x1, int x2, int x3, int x4)
{
	_inputs.push_back(MouseAction(x1, x2, x3, x4));

	if (x1 >= 3)
		return;

	if (x1 != 0)
		Mouse::_buttonStates[x1] = x2;

	_xOld = _x;
	_yOld = _y;
	_x = x3;
	_y = x4;
}

short Mouse::getX()
{
	return short(_x);
}

short Mouse::getY()
{
	return short(_y);
}

bool Mouse::next()
{
	if (_index + 1 >= int(_inputs.size()))
		return false;

	_index++;
	return true;
}

int Mouse::getEventButton()
{
	return _inputs[_index].field_0;
}

bool Mouse::isButtonDown(int btn)
{
	return _buttonStates[btn];
}

void Mouse::reset()
{
	_inputs.clear();
	_index = -1;
}

MouseAction* Mouse::getEvent()
{
	return &_inputs[_index];
}

int Mouse::getButtonState(int btn)
{
	if (btn <= 0 || btn >= 3)
		return 0;

	return _buttonStates[btn];
}

void Mouse::setX(int x)
{
	_x = x;
}

void Mouse::setY(int y)
{
	_y = y;
}

void Mouse::reset2()
{
	_xOld = _x;
	_yOld = _y;
}

int Mouse::getEventButtonState()
{
	return _inputs[_index].field_4;
}
