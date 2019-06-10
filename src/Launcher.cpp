//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Launcher.cpp
//

#include <iostream>
#include "../inc/Core.hpp"
#include "../inc/MenuEventReceiver.hpp"

void	Core::launchSettings()
{
	_menuEventRcv->setClass(&_data);
	_data.device->setEventReceiver(_menuEventRcv);
	_menu->setClass(_data);
	_menu->drawSettings();
}

void	Core::launchMenu()
{
	_menuEventRcv->setClass(&_data);
	_data.device->setEventReceiver(_menuEventRcv);
	_menu->setClass(_data);
	_menu->drawRealMenu();
}

void	Core::launchFirstScreen()
{
	_menuEventRcv->setClass(&_data);
	_data.device->setEventReceiver(_menuEventRcv);
	_menu->setClass(_data);
	_menu->drawFirstScreen();
}

void	Core::launchGame()
{
	_data.inGame = true;
        _game->setClass(&_data);
        _game->getEventRcv()->setClass(&_data);
        _data.device->setEventReceiver(_game->getEventRcv());
        _game->createCharacters();
        _game->drawMap();
	_isFirst = false;
}

void	Core::launchP1Win()
{
	_menuEventRcv->setClass(&_data);
	_data.device->setEventReceiver(_menuEventRcv);
	_menu->setClass(_data);
	_menu->drawP1Win();
}

void	Core::launchP2Win()
{
	_menuEventRcv->setClass(&_data);
	_data.device->setEventReceiver(_menuEventRcv);
	_menu->setClass(_data);
	_menu->drawP2Win();
}

void	Core::launchAIWin()
{	
	_menuEventRcv->setClass(&_data);
	_data.device->setEventReceiver(_menuEventRcv);
	_menu->setClass(_data);
	_menu->drawAIWin();
}