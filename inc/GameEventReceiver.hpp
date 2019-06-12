//
// EPITECH PROJECT, 2018
// OOP_indie_studio_2018
// File description:
// GameEventReceiver.hpp
//

#ifndef GAME_EVENT_RECEIVER_HPP_
#define GAME_EVENT_RECEIVER_HPP_

#include "Globals.hpp"

class GameEventReceiver : public irr::IEventReceiver {
public:
	GameEventReceiver();
	bool	OnEvent(const irr::SEvent &event);
	void	setClass(t_global_data *data);
	bool	isKeyDown(irr::EKEY_CODE keyCode);
private:
	t_global_data	*_data;
	bool		_keyIsDown[irr::KEY_KEY_CODES_COUNT];
};

#endif