/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Draw
*/

#include <iostream>
#include "../inc/Menu.hpp"

void	Menu::drawFirstScreen()
{
	_data.driver->draw2DImage(_firstScreen, irr::core::position2d<irr::s32>(0, 0));
}

void	Menu::drawRealMenu()
{
	_data.guiEnv->clear();
	_data.driver->draw2DImage(_menuImg, irr::core::position2d<irr::s32>(0, 0));
	_data.driver->draw2DImage(_menuSelector, irr::core::position2d<irr::s32>
				  (_data.select_pos[_data.i].first, _data.select_pos[_data.i].second));
}

irr::s32	Menu::drawSettings()
{
	irr::video::ITexture	*exitTexture = _data.driver->getTexture("medias/exit.png");
	irr::video::ITexture	*saveTexture = _data.driver->getTexture("medias/save.png");
	irr::video::ITexture	*nbPlayers = _data.driver->getTexture("medias/case.png");
	irr::video::ITexture	*done = _data.driver->getTexture("medias/case-done.png");
	irr::video::ITexture	*line = _data.driver->getTexture("medias/mute.png");
	irr::video::ITexture	*sound = _data.driver->getTexture("medias/soundWave.png");

	_data.driver->draw2DImage(_menuSettings, irr::core::position2d<irr::s32>(0, 0));
	exitButton = _data.guiEnv->addButton(irr::core::rect<irr::s32>(510, 650, 630, 700),
					     0, ID_BUTTON_EXIT);
	saveButton = _data.guiEnv->addButton(irr::core::rect<irr::s32>(300, 650, 420, 700),
					     0, ID_BUTTON_SAVE);
	playerButton = _data.guiEnv->addButton(irr::core::rect<irr::s32>(198, 232, 249, 285),
					       0, ID_BUTTON_PLAYER);
	mute = _data.guiEnv->addButton(irr::core::rect<irr::s32>(589, 235, 654, 280),
				       0, ID_BUTTON_LINE);
	exitButton->setImage(exitTexture);
	saveButton->setImage(saveTexture);
	if (_data.nbPlayers == 1)
		playerButton->setImage(nbPlayers);
	else if (_data.nbPlayers == 2)
		playerButton->setImage(done);
	return (0);
}

void	Menu::drawP1Win()
{
	_data.driver->draw2DImage(_p1Win, irr::core::position2d<irr::s32>(0, 0));
}

void	Menu::drawP2Win()
{
	_data.driver->draw2DImage(_p2Win, irr::core::position2d<irr::s32>(0, 0));
}

void	Menu::drawAIWin()
{
	_data.driver->draw2DImage(_AIWin, irr::core::position2d<irr::s32>(0, 0));
}
