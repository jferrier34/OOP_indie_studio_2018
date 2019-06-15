//
// EPITECH PROJECT, 2018
// Indie Studio
// File description:
// This is the header file of the Core class
//

#ifndef CORE_HPP_
#define CORE_HPP_

#include <irrlicht.h>
#include "Globals.hpp"
#include "Menu.hpp"
#include "MenuEventReceiver.hpp"
#include "Game.hpp"
#include "GameEventReceiver.hpp"

class Core {
public:
	Core();
	~Core();
	irr::s32	initGlobals();
	void	initMenu();
	void	initGame();
	void	launchSettings();
	void	launchMenu();
	void	launchFirstScreen();
	void	launchGame();
	void	launchP1Win();
	void	launchP2Win();
	void	launchAIWin();
	irr::s32	mainLoop();
private:
	t_global_data		_data;
	Menu			*_menu;
	MenuEventReceiver	*_menuEventRcv;
	Game			*_game;
	GameEventReceiver	*_gameEventRcv;
	bool			_inMenu;
	bool			_inGame;
	bool			_quit;
	bool			_isFirst;
};

#endif
