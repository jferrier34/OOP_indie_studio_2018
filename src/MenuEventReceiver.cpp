/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuEventReceiver
*/

#include <iostream>
#include "../inc/MenuEventReceiver.hpp"
#include "../inc/Menu.hpp"

MenuEventReceiver::MenuEventReceiver() : _data()
{}

void	MenuEventReceiver::set_coordonate(bool direction)
{
	if (direction == true) {
		if (_data->i - 1 < 0)
			_data->i = 3;
		else
			_data->i = _data->i - 1;
	}
	else if (direction == false) {
		if (_data->i + 1 > 3)
			_data->i = 0;
		else
			_data->i = _data->i + 1;

	}
}

void	MenuEventReceiver::parse_cmd()
{
	if (_data->winType == MENU) {
		if (_data->i == 0)
			_data->winType = GAME;
		if (_data->i == 2) {
			_data->winType = SETTINGS;
		}
		else if (_data->i == 3) {
			_data->quit = true;
		}
	}
}

bool					MenuEventReceiver::OnEvent(const irr::SEvent& event)
{
	irr::s32			id;
	irr::s32			scrollbarPos;
	irr::gui::IGUIEnvironment	*env;

	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		if (event.KeyInput.PressedDown) {
			switch (event.KeyInput.Key) {
			case irr::KEY_SPACE:
				if (_data->winType == FSCREEN || _data->winType == P1WIN ||
					_data->winType == P2WIN || _data->winType == IAWIN)
					_data->winType = MENU;
				break;
			case irr::KEY_UP:
				set_coordonate(true);
				break;
			case irr::KEY_DOWN:
				set_coordonate(false);
				break;
			case irr::KEY_RETURN:
				parse_cmd();
				break;
			case irr::KEY_ESCAPE:
				_data->quit = true;
				break;
			default:
				break;
			}
		}
	}
	if (event.EventType == irr::EET_GUI_EVENT) {
		id = event.GUIEvent.Caller->getID();
		env = _data->device->getGUIEnvironment();
		switch (event.GUIEvent.EventType) {
		case irr::gui::EGET_SCROLL_BAR_CHANGED:
			if (id == ID_BUTTON_PLAYER) {
				scrollbarPos = ((irr::gui::IGUIScrollBar*)event.GUIEvent.Caller)->getPos();
			}
			break;
		default:
			break;
		}
	}
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
		if (event.MouseInput.Event == irr::EMIE_LMOUSE_PRESSED_DOWN &&
		    (_data->winType == SETTINGS)) {
			if ((event.MouseInput.X >= 300 && event.MouseInput.X <= 420) &&
			    (event.MouseInput.Y >= 650 && event.MouseInput.Y <= 700))
				_data->winType = MENU;
			else if ((event.MouseInput.X >= 510 && event.MouseInput.X <= 630) &&
				 (event.MouseInput.Y >= 650 && event.MouseInput.Y <= 700))
				_data->winType = MENU;
			else if ((event.MouseInput.X >= 198 && event.MouseInput.X <= 249) &&
				 (event.MouseInput.Y >= 232 && event.MouseInput.Y <= 285) &&
				 _data->nbPlayers == 1)
				_data->nbPlayers = 2;
			else if ((event.MouseInput.X >= 198 && event.MouseInput.X <= 249) &&
                                 (event.MouseInput.Y >= 232 && event.MouseInput.Y <= 285) &&
				 _data->nbPlayers == 2)
				_data->nbPlayers = 1;
			else if ((event.MouseInput.X >= 589 && event.MouseInput.X <= 654) &&
				  (event.MouseInput.Y >= 235 && event.MouseInput.Y <= 280) &&
				  _data->sound == true)
				_data->sound = false;
			else if ((event.MouseInput.X >= 589 && event.MouseInput.X <= 654) &&
				  (event.MouseInput.Y >= 235 && event.MouseInput.Y <= 280) &&
				  _data->sound == false)
				_data->sound = true;
		}
		else
			return (true);
	}
	return (false);
}

void	MenuEventReceiver::setClass(t_global_data *data)
{
	_data = data;
}
