/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Core
*/

#include <iostream>
#include "../inc/Core.hpp"
#include "../inc/MenuEventReceiver.hpp"

Core::Core() : _data(), _menu(nullptr), _inMenu(false), _inGame(false), _quit(false),
	       _isFirst(true)
{}

Core::~Core()
{
	_data.device->drop();
	_data.soundEng->drop();
}

int Core::initGlobals()
{
	_data.device = irr::createDevice(irr::video::EDT_SOFTWARE,
					 irr::core::dimension2d<irr::u32>(945, 756),32,
					 false, false, false, nullptr);
	_data.device->setWindowCaption(L"Indie Studio - Bomberman with Irrlicht");
	_data.device->setResizable(false);
	_data.driver = _data.device->getVideoDriver();
	_data.sceneMngr = _data.device->getSceneManager();
	_data.soundEng = irrklang::createIrrKlangDevice();
	_data.soundEng->play2D("medias/ShookOnes.ogg", true, false);
	_data.guiEnv = _data.device->getGUIEnvironment();
	_data.winType = FSCREEN;
	_data.inMenu = false;
	_data.inGame = false;
	_data.select_pos[0] = std::make_pair(271, 217);
	_data.select_pos[1] = std::make_pair(271, 340);
	_data.select_pos[2] = std::make_pair(271, 448);
	_data.select_pos[3] = std::make_pair(360, 544);
	_data.i = 0;
	_data.sound = true;
	_data.nbPlayers = 1;
	_data.quit = false;
	return 0;
}

void	Core::initMenu()
{
	_menu = new Menu;
	_menu->setClass(_data);
	_menu->initTextures();
	_menuEventRcv = new MenuEventReceiver;
	_menuEventRcv->setClass(&_data);
	_data.device->setEventReceiver(_menuEventRcv);
}

void	Core::initGame()
{
	if (!_isFirst) {
		delete _game;
	}
	_game = new Game;
	_game->setClass(&_data);
	_game->initMap();
}

irr::s32	Core::mainLoop()
{
	initGlobals();
	initMenu();
	initGame();
	while (_data.device->run() && _data.quit == false) {
		_data.driver->beginScene(true, false, irr::video::SColor(255, 102, 102, 136));
		switch (_data.winType) {
		case MENU:
			launchMenu();
			break;
		case FSCREEN:
			launchFirstScreen();
			break;
		case SETTINGS:
			launchSettings();
			break;
		case GAME:
			if (!_isFirst)
				initGame();
			launchGame();
			break;
		case P1WIN:
			launchP1Win();
			break;
		case P2WIN:
			launchP2Win();
			break;
		case IAWIN:
			launchAIWin();
			break;
		default:
			break;
		}
		_data.sceneMngr->drawAll();
		_data.guiEnv->drawAll();
		_data.driver->endScene();
	}
	return 0;
}
