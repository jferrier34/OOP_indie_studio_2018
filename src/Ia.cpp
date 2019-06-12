//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include "../inc/Ia.hpp"

Ia::Ia(irr::video::ITexture *texture, irr::scene::IAnimatedMesh *mesh,
       irr::s32 x, irr::s32 y, irr::s32 rotation) : _texture(texture), _mesh(mesh), _x(x), _y(y),
				     _rotation(rotation), _isBombDrp(false)
{
	_startRotation = irr::core::vector3df(0, 0, 0);
	_scale = irr::core::vector3df(15, 30, 10);
}

Ia::~Ia()
{
	_data->sceneMngr->addToDeletionQueue(_node);
}

irr::s32     Ia::getX()
{
        return _x;
}

irr::s32     Ia::getY()
{
        return _y;
}

irr::s32     Ia::getSaveX()
{
        return _saveX;
}

irr::s32     Ia::getSaveY()
{
        return _saveY;
}

irr::scene::IAnimatedMeshSceneNode *Ia::getNode()
{
        return _node;
}

void    Ia::setSaveX(irr::s32 x)
{
        _saveX = x;
}

void    Ia::setSaveY(irr::s32 y)
{
        _saveY = y;
}

void    Ia::setClass(t_global_data *data)
{
        _data = data;
}

void    Ia::createNode()
{
 	_node = _data->sceneMngr->addAnimatedMeshSceneNode(_mesh, 0, -1,
                                                          _pos, _startRotation, _scale);
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMaterialTexture(0, _texture);
        setRotation();
        setPosition(_x, _y, -540);
        setScale(_scale.X, _scale.Y, _scale.Z);
}

void    Ia::setScale(irr::f32 x, irr::f32 y, irr::f32 z)
{
        if (_node)
                _node->setScale(irr::core::vector3df(x, y, z));
}

void    Ia::setPosition(irr::s32 x, irr::s32 y, irr::s32 z)
{
	if (_node) {
                _node->setPosition(irr::core::vector3df(-537 + (60 * x), -510 + (60 * y), z));
                _x = x;
                _y = y;
	}
}

void    Ia::setRotation()
{
	irr::s32     z = 0;

	if (_rotation) {
		switch (_rotation) {
		case RIGHT:
                        z = 70;
			break;
		case LEFT:
                        z = -100;
			break;
		case UP:
                        z = -20;
			break;
		case DOWN:
                        z = 160;
			break;
		default:
                        break;
		}
                _node->setRotation(irr::core::vector3df(100, 1, z));
	}
}
