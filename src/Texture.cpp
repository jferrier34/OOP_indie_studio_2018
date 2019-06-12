//
// EPITECH PROJECT, 2018
// Indie Studio
// File description:
// Source file of the Texture class
//

#include <iostream>
#include "../inc/Texture.hpp"

LText::LText() : _bloc(nullptr), _perso(nullptr), _wall(nullptr), _brick(nullptr), _ground(nullptr),
		 _bombUp(nullptr), _bombLvUp(nullptr), _bomb(nullptr), _bombText(nullptr), _data()
{}

irr::video::ITexture *LText::getFirstPlayer()
{
    return (_firstPlayer);
}

irr::video::ITexture *LText::getSecondPlayer()
{
    return (_secondPlayer);
}

/*irr::video::ITexture *LText::getP3()
{
    return (_p3);
}

irr::video::ITexture *LText::getP4()
{
    return (_p4);
    }*/

irr::video::ITexture *LText::getWall()
{
    return (_wall);
}

irr::scene::IAnimatedMesh *LText::getBloc()
{
    return (_bloc);
}

irr::scene::IAnimatedMesh *LText::getCharacterMesh()
{
    return (_perso);
}

irr::scene::IAnimatedMesh *LText::getFire()
{
	return (_fire);
}

irr::video::ITexture *LText::getBrick()
{
    return (_brick);
}

irr::video::ITexture *LText::getvBombUp()
{
    return (_bombUp);
}

irr::video::ITexture *LText::getBombLvUp()
{
    return (_bombLvUp);
}

irr::scene::IAnimatedMesh *LText::getBomb()
{
    return (_bomb);
}

irr::video::ITexture *LText::getGround()
{
    return (_ground);
}

irr::video::ITexture *LText::getBombText()
{
    return (_bombText);
}

irr::video::ITexture *LText::getFireText()
{
    return (_fireText);
}

irr::video::ITexture *LText::getIa()
{
	return (_ia);
}

void	LText::setClass(t_global_data *data)
{
	_data = data;
}

irr::s32  LText::loadTextures()
{
	if ((_bomb = _data->sceneMngr->getMesh("medias/bomb.dae")) == nullptr) {
		std::cout << "_bomb failed\n";
		return -1;
	}
	if ((_bombText = _data->driver->getTexture("medias/bomb.png")) == nullptr) {
		std::cout << "_bombText failed\n";
		return -1;
	}
	if ((_bloc = _data->sceneMngr->getMesh("medias/brick_menu.dae")) == nullptr) {
		std::cout << "_bloc failed\n";
		return -1;
	}
	if ((_perso = _data->sceneMngr->getMesh("medias/bomberman.b3d")) == nullptr) {
		std::cout << "bomberman mesh failed\n";
		return -1;
	}
	if ((_fireText = _data->driver->getTexture("medias/fire.png")) == nullptr) {
		std::cout << "fireText failed\n";
		return -1;
	}
	if ((_fire = _data->sceneMngr->getMesh("medias/fire.obj")) == nullptr) {
		std::cout << "fire failed\n";
		return -1;
	}
	if ((_firstPlayer = _data->driver->getTexture("medias/PlayerColorSetOne.png")) == nullptr)
		std::cout << "firstPlayer failed\n";
	if ((_secondPlayer = _data->driver->getTexture("medias/PlayerColorSetOneTwo.png")) == nullptr)
		std::cout << "firstPlay failed\n";
	if  ((_ground = _data->driver->getTexture("medias/ground.jpg")) == nullptr)
		std::cout << "ground failed\n";
	if ((_wall = _data->driver->getTexture("medias/wall.jpg")) == nullptr)
		std::cout << "wall failed\n";
	if ((_brick = _data->driver->getTexture("medias/RTS_Crate.png")) == nullptr) {
		return (-1);
	}
	if ((_ia = _data->driver->getTexture("medias/PlayerColorSetIa.png")) == nullptr) {
		std::cout << "IA failed\n";
	}
	return (0);
}