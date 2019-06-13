//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "bomberman.hpp"
#include "Globals.hpp"

#ifndef TEXT_HPP_
# define TEXT_HPP_

class LText {
public:
	LText();
	~LText() = default;
	irr::scene::IAnimatedMesh *getBloc();
	irr::scene::IAnimatedMesh *getCharacterMesh();
	irr::video::ITexture	*getFirstPlayer();
	irr::video::ITexture	*getSecondPlayer();
	/*irr::video::ITexture	*getP3();
	irr::video::ITexture	*getP4();*/
	irr::video::ITexture	*getWall();
	irr::video::ITexture	*getBrick();
	irr::video::ITexture	*getGround();
	irr::video::ITexture	*getvBombUp();
	irr::video::ITexture	*getBombLvUp();
	irr::video::ITexture	*getFireText();
	irr::scene::IAnimatedMesh *getBomb();
	irr::video::ITexture	*getBombText();
	irr::scene::IAnimatedMesh *getFire();
	irr::video::ITexture	*getIa();
	void			setClass(t_global_data *data);
	irr::s32 loadTextures();
private:
	irr::scene::IAnimatedMesh *_bloc;
	irr::scene::IAnimatedMesh *_perso;
	irr::scene::IAnimatedMesh *_fire;
	irr::video::ITexture *_firstPlayer;
	irr::video::ITexture *_secondPlayer;
	irr::video::ITexture *_ia;
	irr::video::ITexture *_fireText;
	/*irr::video::ITexture *_p3;
	irr::video::ITexture *_p4;*/
	irr::video::ITexture *_wall;
	irr::video::ITexture *_brick;
	irr::video::ITexture *_ground;
	irr::video::ITexture *_bombUp;
	irr::video::ITexture *_bombLvUp;
	irr::scene::IAnimatedMesh *_bomb;
	irr::video::ITexture *_bombText;
	t_global_data		*_data;
};

#endif /* !TEXT_HPP */
