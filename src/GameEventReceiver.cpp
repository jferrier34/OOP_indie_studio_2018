/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** GameEventReceiver
*/

#include <iostream>
#include "../inc/GameEventReceiver.hpp"

GameEventReceiver::GameEventReceiver() : _data()
{
	for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; i++) {
		_keyIsDown[i] = false;
	}
}

bool	GameEventReceiver::OnEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		_keyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
	}
	return false;
}

bool	GameEventReceiver::isKeyDown(irr::EKEY_CODE keyCode)
{
	return _keyIsDown[keyCode];
}

void	GameEventReceiver::setClass(t_global_data *data)
{
	_data = data;
}
