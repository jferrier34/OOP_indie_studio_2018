//
// EPITECH PROJECT, 2018
// Indie Studio
// File description:
// Source file for the header files
//

#include <iostream>
#include "../inc/Character.hpp"

Character::Character(irr::video::ITexture *texture, irr::scene::IAnimatedMesh *mesh,
		     irr::s32 x, irr::s32 y, irr::s32 rotation) : _texture(texture), _mesh(mesh), _x(x), _y(y),
						   _rotation(rotation), _isBombDrp(false)
{
	_startRotation = irr::core::vector3df(0, 0, 0);
	_scale = irr::core::vector3df(15, 17, 8);
}

Character::~Character()
{
	_data->sceneMngr->addToDeletionQueue(_node);
}

irr::s32	Character::getX()
{
	return _x;
}

irr::s32	Character::getY()
{
	return _y;
}

irr::s32	Character::getSaveX()
{
	return _saveX;
}

irr::s32	Character::getSaveY()
{
	return _saveY;
}

void	Character::setSaveX(irr::s32 x)
{
	_saveX = x;
}

void	Character::setSaveY(irr::s32 y)
{
	_saveY = y;
}

void	Character::setClass(t_global_data *data)
{
	_data = data;
}

void	Character::createNode()
{
	_node = _data->sceneMngr->addAnimatedMeshSceneNode(_mesh, 0, -1,
							  _pos, _startRotation, _scale);
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_node->setMaterialTexture(0, _texture);
	setPosition(_x, _y, -540);
	setScale(_scale.X, _scale.Y, _scale.Z);
}

void	Character::setScale(irr::f32 x, irr::f32 y, irr::f32 z)
{
	if (_node)
		_node->setScale(irr::core::vector3df(x, y, z));
}

void	Character::setPosition(irr::s32 x, irr::s32 y, irr::s32 z)
{
	if (_node) {
		_node->setPosition(irr::core::vector3df(-530 + (60 * x), -510 + (60 * y), z));
		_x = x;
		_y = y;
	}
}

void	Character::setRotation(irr::s32 i)
{
	irr::s32	z = 0;

	if (i) {
		switch (i) {
		case 4:
			z = 70;
			break;
		case 2:
			z = -100;
			break;
		case 1:
			z = -20;
			break;
		case 3:
			z = 160;
			break;
		default:
			break;
			}
		_node->setRotation(irr::core::vector3df(100, 1, z));
	}
}

irr::scene::IAnimatedMeshSceneNode	*Character::getNode() {
	return _node;
}