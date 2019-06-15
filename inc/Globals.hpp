//
// EPITECH PROJECT, 2018
// OOP_indie_studio_2018
// File description:
// Globals.hpp
//

#ifndef GLOBALS_HPP_
#define GLOBALS_HPP_

#include <irrlicht.h>
#include <map>
#include <utility>
#include <chrono>
#include <ctime>
#include <iostream>

enum Window_Type {
	FSCREEN,
	MENU,
	SAVES,
	SETTINGS,
	GAME,
	HIGHSCORE,
	HELP,
	PAUSE,
	P1WIN,
	P2WIN,
	IAWIN,
	END_GAME
};

enum Rotation {
	RIGHT,
	LEFT,
	UP,
	DOWN
};

typedef struct	s_global_data {
	irr::IrrlichtDevice		*device;
	irr::video::IVideoDriver	*driver;
	irr::scene::ISceneManager	*sceneMngr;
	irr::gui::IGUIEnvironment	*guiEnv;
        Window_Type			winType;
        bool				inMenu;
        bool				inGame;
	bool				quit;
	bool				sound;
	std::map			<irr::s32, std::pair<irr::s32, irr::s32>> select_pos;
	irr::s32				i;
	irr::s32				nbPlayers;
}		t_global_data;

#endif
