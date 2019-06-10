//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Menu.hpp
//

#include <iostream>
#include "../inc/Menu.hpp"

Menu::Menu() : _firstScreen(nullptr), _menuImg(nullptr), _menuSelector(nullptr),
	       _menuSettings(nullptr), _p1Win(nullptr), _p2Win(nullptr)
{
}

void	Menu::initTextures()
{
	_firstScreen = _data.driver->getTexture("medias/firstScreen.png");
	_menuImg = _data.driver->getTexture("medias/background_menu.png");
	_menuSelector = _data.driver->getTexture("medias/bomber-logo.png");
	_menuSettings = _data.driver->getTexture("medias/menu-settings.png");
	_p1Win = _data.driver->getTexture("medias/p1Win.png");
	_p2Win = _data.driver->getTexture("medias/p2Win.png");
	_AIWin = _data.driver->getTexture("medias/AIWin.png");
}

void	Menu::setClass(t_global_data data)
{
	_data = data;
}
