//
// EPITECH PROJECT, 2018
// OOP_indie_studio_2018
// File description:
// La.hpp
//

#ifndef IA_HPP_
# define IA_HPP_

#include "Globals.hpp"

class Ia {
public:
	Ia(irr::video::ITexture *texture, irr::scene::IAnimatedMesh *mesh, int x, int y, int rotation);
	~Ia();
	void	setClass(t_global_data *data);
	void	createNode();
	void	setPosition(irr::s32 x, irr::s32 y, irr::s32 z);
	void	setRotation();
	void	setScale(irr::f32 x, irr::f32 y, irr::f32 z);
	irr::s32	getX();
	irr::s32	getY();
	irr::s32	getSaveX();
	irr::s32	getSaveY();
	void	setSaveX(irr::s32 x);
	void	setSaveY(irr::s32 y);
	irr::scene::IAnimatedMeshSceneNode*	getNode();
private:
	irr::video::ITexture			*_texture;
	irr::scene::IAnimatedMesh		*_mesh;
	irr::scene::IAnimatedMeshSceneNode	*_node;
	irr::core::vector3df			_startRotation;
	irr::core::vector3df			_pos;
	irr::core::vector3df			_scale;
	irr::s32					_rotation;
	t_global_data				*_data;
	irr::s32					_x;
	irr::s32					_y;
	irr::s32					_saveX;
	irr::s32					_saveY;
	bool					_isBombDrp;
};

#endif
