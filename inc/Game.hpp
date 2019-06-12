//
// EPITECH PROJECT, 2018
// OOP_indie_studio_2018
// File description:
// Game.hpp
//

#ifndef GAME_HPP_
# define GAME_HPP_

#include "bomberman.hpp"
#include "Texture.hpp"
#include "Character.hpp"
#include "Globals.hpp"
#include "Ia.hpp"
#include "GameEventReceiver.hpp"
#include <utility>

# define GROUND 0
# define WALL 1
# define BRK 2
# define BOMBLVUP 3
# define BOMBUP 4
# define EXPLO 5

# define HEIGHT 20
# define WIDTH 20

# define WIN_X 800
# define WIN_y 600
# define INIT_X -550
# define INIT_Y -550
# define INIT_Z -600
# define ECART_X 62
# define ECART_Y 62

# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

class Game {
public:
	Game();
	~Game() = default;
	void	drawMap();
	void	makeMap();
	void	initMap();
	void	corner();
	irr::s32	myRandom(irr::s32 b);
	void	getWay();
	void	setClass(t_global_data *data);
	void	createCharacters();
	void	getGameEvents();
	void	moveUpPlayer(Character *character);
	void	moveLeftPlayer(Character *character);
	void	moveDownPlayer(Character *character);
	void	moveRightPlayer(Character *character);
	void	fdropBomb(Character *character);
	void	sdropBomb(Character *character);
	void	getBombEvents();
	void	getExploEvents();
	void	getPlayerEvents();
	void	updateMap(irr::s32 x, irr::s32 y);
	void	updateMapExp(irr::s32 x, irr::s32 y);
	void    findWayFia();
        void    findWaySia();
	void	findWayTia();
        void    fIaDropBomb();
        void    sIaDropBomb();
	void	tIaDropBomb();
        void    getIaEvents();
        void    moveIa(Ia *ia);
        void    moveIaDodgeBomb(Ia *ia);
        void    moveIaFromBomb(Ia *ia);
        int     moveIaY(Ia *ia);
        int     moveIaX(Ia *ia);
        int     moveIaUpX(Ia *ia);
        int     moveIaDownX(Ia *ia);
        int     moveIaUpY(Ia *ia);
        int     moveIaDownY(Ia *ia);
	bool	Win();
	void	deleteNodesIa();
	void	deleteMapNodes();
	void	deleteNodesPlayer(Character *character);
	GameEventReceiver	*getEventRcv();
private:
	t_global_data					*_data;
	std::vector<std::vector<char>>			_map;
	LText						*_text;
	irr::scene::IAnimatedMesh			*_mesh;
	irr::scene::IAnimatedMeshSceneNode		*_node;
	std::map<std::pair<int, int>, irr::scene::IAnimatedMeshSceneNode *>	_ground;
	irr::s32						_sizeY;
	irr::s32						_sizeX;
	Character					*_first;
	Character					*_second;
	Ia						*_firstIa;
	Ia						*_secondIa;
	Ia						*_thirdIa;
	GameEventReceiver					*_gameEventRcv;
	irr::scene::IAnimatedMesh				*_fpBomb;
	irr::video::ITexture					*_fpBombText;
	irr::scene::IAnimatedMeshSceneNode			*_bombNode;
	irr::scene::IAnimatedMeshSceneNode			*_sbombNode;
	irr::scene::IAnimatedMesh				*_exploMesh;
	irr::video::ITexture					*_exploText;
	irr::scene::IAnimatedMeshSceneNode			*_exploNode;
	irr::scene::IAnimatedMeshSceneNode			*_sexploNode;
	std::chrono::time_point<std::chrono::system_clock>	_bombTStart;
	std::chrono::time_point<std::chrono::system_clock>	_bombTEnd;
	std::chrono::time_point<std::chrono::system_clock>	_sbombTStart;
	std::chrono::time_point<std::chrono::system_clock>	_sbombTEnd;
	std::chrono::time_point<std::chrono::system_clock>	_fireTStart;
	std::chrono::time_point<std::chrono::system_clock>	_fireTEnd;
	std::chrono::time_point<std::chrono::system_clock>	_sfireTStart;
	std::chrono::time_point<std::chrono::system_clock>	_sfireTEnd;
	irr::scene::IAnimatedMeshSceneNode                      *_iaFirstNode;
        irr::scene::IAnimatedMeshSceneNode                      *_iaScdNode;
	irr::scene::IAnimatedMeshSceneNode			*_iaThirdNode;
	std::chrono::time_point<std::chrono::system_clock>      _fIaBombStart;
        std::chrono::time_point<std::chrono::system_clock>      _fIaBombEnd;
        std::chrono::time_point<std::chrono::system_clock>      _fiaFireStart;
        std::chrono::time_point<std::chrono::system_clock>      _fiaFireEnd;	
        std::chrono::time_point<std::chrono::system_clock>      _sIaBombStart;
        std::chrono::time_point<std::chrono::system_clock>      _sIaBombEnd;
        std::chrono::time_point<std::chrono::system_clock>      _siaFireStart;
        std::chrono::time_point<std::chrono::system_clock>      _siaFireEnd;
	
	std::chrono::time_point<std::chrono::system_clock>      _tIaBombStart;
        std::chrono::time_point<std::chrono::system_clock>      _tIaBombEnd;
        std::chrono::time_point<std::chrono::system_clock>      _tiaFireStart;
        std::chrono::time_point<std::chrono::system_clock>      _tiaFireEnd;
	bool                                                    _fIaBombSted;
        bool                                                    _fIaExploSted;
        bool                                                    _sIaBombSted;
        bool                                                    _sIaExploSted;
	bool							_tIaBombSted;
	bool							_tIaExploSted;
	irr::s32                                                _fIaBombX;
	irr::s32                                                _fIaBombY;
	irr::s32                                                _sIaBombX;
	irr::s32                                                _sIaBombY;
	irr::s32						_tIaBombX; 
        irr::s32	      					_tIaBombY;
	bool							_fisStarted;
	bool							_sisStarted;
	bool							_fireStarted;
	bool							_sfireStarted;
	irr::s32						_stkX;
	irr::s32						_stkY;
	irr::s32						_saveX;
	irr::s32						_saveY;
};

#endif
