/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.cpp
*/

#include "../inc/bomberman.hpp"
#include "../inc/Game.hpp"
#include "../inc/Texture.hpp"

void	Game::initMap()
{
	_map.resize(20, std::vector<char>(20, 1));
        getWay();
        corner();
	_text = new LText;
	_text->setClass(_data);
	_text->loadTextures();
	_gameEventRcv = new GameEventReceiver;
        _gameEventRcv->setClass(_data);
	_exploMesh = _text->getFire();
	_exploText = _text->getFireText();
}

GameEventReceiver	*Game::getEventRcv()
{
	return _gameEventRcv;
}

void    Game::corner()
{
        _map[2][1] = GROUND;
        _map[1][1] = GROUND;
	_map[1][2] = GROUND;

        _map[1][HEIGHT - 2] = GROUND;
        _map[2][HEIGHT - 2] = GROUND;
        _map[1][HEIGHT - 3] = GROUND;

        _map[WIDTH - 3][1] = GROUND;
        _map[WIDTH - 2][1] = GROUND;
        _map[WIDTH - 2][2] = GROUND;

        _map[WIDTH - 3][HEIGHT - 2] = GROUND;
        _map[WIDTH - 2][HEIGHT - 3] = GROUND;
        _map[WIDTH - 2][HEIGHT - 2] = GROUND;

        _map[1][(HEIGHT / 2) + 1] = WALL;
        _map[1][(HEIGHT / 2) + 2] = WALL;
        _map[WIDTH - 2][(HEIGHT / 2) - 1] = WALL;
        _map[(WIDTH / 2) + 1][HEIGHT - 2] = WALL;
        _map[(WIDTH / 2) - 1][1] = WALL;
}

int     Game::myRandom(int b)
{
        return (rand() % b);
}

void    Game::getWay()
{
	irr::s32	x = 0;
	irr::s32	y = 0;
	irr::s32        k = 0;

        srand(time(NULL));
	while (++y < HEIGHT - 1) {
                if (y == 1 || y == HEIGHT / 2 || y == HEIGHT - 2) {
                        while (++x != WIDTH - 2) {
                                k = myRandom(100);
                                if (k < 30)
                                        _map[x][y] = GROUND;
		                else {
                                        _map[x][y] = BRK;
                                }
                        }
                        x = 1;
		}
                else {
                      	k = myRandom(100);
                        if (k < 30)
                                _map[1][y] = GROUND;
                        else {
                                _map[1][y] = BRK;
			}
                        x++;
                        while (++x != WIDTH - 2) {
                                k = myRandom(100);
                                if (k > 70)
                                _map[x][y] = WALL;
				else if (k < 30) {
                                        _map[x][y] = GROUND;
	                        }
                                else {
                                        _map[x][y] = BRK;
                                }
                        }

		}
                x = 0;
                k = myRandom(100);
                if (k < 30)
                        _map[WIDTH - 2][y] = GROUND;
                else {
                        _map[WIDTH - 2][y] = BRK;
                }
	}
        x = WIDTH / 2;
        y = 0;
        while (++y != HEIGHT - 1) {
		k = myRandom(100);
                if (k < 30)
                        _map[x][y] = GROUND;
                else {
                        _map[x][y] = BRK;
                }
        }
}

void Game::makeMap()
{
	irr::scene::IAnimatedMeshSceneNode *tile = nullptr;	
	irr::video::ITexture *te = nullptr;
	std::pair<irr::s32, irr::s32>	tmp;
	irr::s32 x = INIT_X;
	irr::s32 y = INIT_Y;
	irr::s32 z = INIT_Z;
	irr::s32 sx = 0;
	irr::s32 sy = 0;
	irr::f32 r = 2.0;

	_text->setClass(_data);
	_sizeX = _map.size();
	_sizeY = _map[0].size();
	for (irr::s32 i = 0; i < _map.size(); i++)
	{
		for (irr::s32 j = 0; j < _map[i].size(); j++)
		{
			if (_map[i][j] == GROUND) {
				z = INIT_Z - 30;
				te = _text->getGround();
				r = 1.9f;
			} else if (_map[i][j] == WALL) {
				z = INIT_Z;
				te = _text->getWall();
				r = 1.9f;
			} else if (_map[i][j] == BRK) {
				z = INIT_Z;
				te = _text->getBrick();
				r = 1.9f;
			}
			tile = _data->sceneMngr->addAnimatedMeshSceneNode(_text->getBloc(),
									  0, -1,
									  irr::core::vector3df(x, y, z),
									  irr::core::vector3df(0.0f, 0.0f, 0.0f),
									  irr::core::vector3df(1.86f, 1.86f, 1.86f));
			tile->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			tile->setMaterialTexture(0, te);
			tmp = std::make_pair(sx, sy);
			_ground[tmp] = tile;
			y += ECART_Y;
			sy++;
		}
		x += ECART_X;
		sx++;
		sy = 0;
		y = INIT_Y;
	}
}

Game::Game() : _data(), _map(), _text(nullptr), _mesh(nullptr), _node(nullptr),
	       _fpBomb(nullptr), _fpBombText(nullptr), _bombNode(nullptr), _sbombNode(nullptr),
	       _exploMesh(nullptr), _exploText(nullptr), _exploNode(nullptr), _sexploNode(nullptr),
	       _fisStarted(false), _sisStarted(false)
{}

void	Game::setClass(t_global_data *data)
{
	_data = data;
}

void	Game::moveUpPlayer(Character *character)
{
	if (_map[character->getX()][character->getY() + 1] == GROUND) {
		character->setPosition(character->getX(), character->getY() + 1, -540);
		character->setRotation(1);
	}
	else
		character->setPosition(character->getX(), character->getY(), -540);
	
}

void	Game::moveLeftPlayer(Character *character)
{
	if (_map[character->getX() + 1][character->getY()] == GROUND) {
		character->setPosition(character->getX() + 1, character->getY(), -540);
		character->setRotation(2);
	}
	else
		character->setPosition(character->getX(), character->getY(), -540);
}

void	Game::moveDownPlayer(Character *character)
{
	if (_map[character->getX()][character->getY() - 1] == GROUND) {
		character->setPosition(character->getX(), character->getY() - 1, -540);
		character->setRotation(3);
	}
	else
		character->setPosition(character->getX(), character->getY(), -540);
}

void	Game::moveRightPlayer(Character *character)
{
	if (_map[character->getX() - 1][character->getY()] == GROUND) {
		character->setPosition(character->getX() - 1, character->getY(), -540);
		character->setRotation(4);
	}
	else
		character->setPosition(character->getX(), character->getY(), -540);
}

void	Game::fdropBomb(Character *character)
{
	if (!_fisStarted && !_fireStarted) {
		_fpBomb = _text->getBomb();
		_fpBombText = _text->getBombText();
		_bombTStart = std::chrono::system_clock::now();
		if (_fireStarted == false)
			_fisStarted = true;
		_bombNode = _data->sceneMngr->addAnimatedMeshSceneNode(_fpBomb, 0, -1,
								       irr::core::vector3df(-530 + (60 *character->getX()), -510 + (60 *character->getY()), -540),
								       irr::core::vector3df(0, 0, 0),
								       irr::core::vector3df(0.8f, 0.8f, 0.8f));
		_bombNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_bombNode->setMaterialTexture(0, _fpBombText);
		character->setSaveX(character->getX());
		character->setSaveY(character->getY());
	}
}

void	Game::sdropBomb(Character *character)
{
	if (!_sisStarted && !_sfireStarted) {
		_fpBomb = _text->getBomb();
		_fpBombText = _text->getBombText();
		_sbombTStart = std::chrono::system_clock::now();
		_sisStarted = true;
		_sbombNode = _data->sceneMngr->addAnimatedMeshSceneNode(_fpBomb, 0, -1,
									irr::core::vector3df(-530 + (60 *character->getX()), -510 + (60 *character->getY()), -540),
									irr::core::vector3df(0, 0, 0),
									irr::core::vector3df(0.8f, 0.8f, 0.8f));
		_sbombNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_sbombNode->setMaterialTexture(0, _fpBombText);
		character->setSaveX(character->getX());
		character->setSaveY(character->getY());
	}
}

void	Game::updateMap(irr::s32 x, irr::s32 y)
{
	irr::s32	i;
	irr::s32	j;
	std::pair<irr::s32, irr::s32>	tmp;
	irr::scene::IAnimatedMeshSceneNode	*tmp_node;
	irr::core::vector3df		node_pos;

	i = -520 + (60 * x);
	j = -510 + (60 * y);
	if (_map[x + 1][y] == EXPLO && (_map[x + 2][y] == WALL
					|| _map[x + 2][y] == BRK
					|| _map[x + 2][y] == GROUND)) {
		tmp = std::make_pair(x + 1, y);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getGround());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		
		_map[x + 1][y] = GROUND;
	}
	else if (_map[x + 1][y] == EXPLO && _map[x + 2][y] == EXPLO) {
		tmp = std::make_pair(x + 1, y);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getGround());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		tmp = std::make_pair(x + 2, y);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getGround());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x + 2][y] = GROUND;
		_map[x + 1][y] = GROUND;
	}
	if (_map[x - 1][y] == EXPLO && (_map[x - 2][y] == WALL
					|| _map[x - 2][y] == BRK
					|| _map[x - 2][y] == GROUND)) {
		tmp = std::make_pair(x - 1, y);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getGround());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x - 1][y] = GROUND;
		
	}
	else if (_map[x - 1][y] == EXPLO && _map[x - 2][y] == EXPLO) {
		tmp = std::make_pair(x - 1, y);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getGround());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		tmp = std::make_pair(x - 2, y);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getGround());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x - 2][y] = GROUND;
		_map[x - 1][y] = GROUND;
	}
	if (_map[x][y + 1] == EXPLO && (_map[x][y + 2] == WALL
					|| _map[x][y + 2] == BRK
					|| _map[x][y + 2] == GROUND)) {
		tmp = std::make_pair(x, y + 1);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getGround());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x][y + 1] = GROUND;
	}
	else if (_map[x][y + 1] == EXPLO && _map[x][y + 2] == EXPLO) {
		tmp = std::make_pair(x, y + 1);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getGround());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		tmp = std::make_pair(x, y + 2);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getGround());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x][y + 2] = GROUND;
		_map[x][y + 1] = GROUND;
	}
	if (_map[x][y - 1] == EXPLO && (_map[x][y - 2] == WALL
					|| _map[x][y - 2] == BRK
					|| _map[x][y - 2] == GROUND)) {
		tmp = std::make_pair(x, y - 1);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getGround());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x][y - 1] = GROUND;
	}
	else if (_map[x][y - 1] == EXPLO && _map[x][y - 2] == EXPLO) {
		tmp = std::make_pair(x, y - 1);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getGround());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		tmp = std::make_pair(x, y - 2);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getGround());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x][y - 2] = GROUND;
		_map[x][y - 1] = GROUND;
	}
	tmp = std::make_pair(x, y);
	tmp_node = _ground[tmp];
	tmp_node->setMaterialTexture(0, _text->getGround());
	node_pos = tmp_node->getPosition();
	node_pos.Z = INIT_Z - 30;
	tmp_node->setPosition(node_pos);
	_map[x][y] = GROUND;
}


void	Game::updateMapExp(irr::s32 x, irr::s32 y)
{
	irr::s32	i;
	irr::s32	j;
	std::pair<irr::s32, irr::s32>	tmp;
	irr::scene::IAnimatedMeshSceneNode	*tmp_node;
	irr::core::vector3df		node_pos;

	i = -520 + (60 * x);
	j = -510 + (60 * y);
	if ((_map[x + 1][y] == BRK) || (_map[x + 1][y] == GROUND && _map[x + 2][y] == WALL)) {
		tmp = std::make_pair(x + 1, y);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getFireText());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x + 1][y] = EXPLO;
	}
	else if ((_map[x + 1][y] == GROUND && _map[x + 2][y] == BRK) ||
		 (_map[x + 1][y] == GROUND && _map[x + 2][y] == GROUND)) {
		tmp = std::make_pair(x + 2, y);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getFireText());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		tmp = std::make_pair(x + 1, y);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getFireText());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x + 2][y] = EXPLO;
		_map[x + 1][y] = EXPLO;
	}
	if ((_map[x - 1][y] == BRK) || (_map[x - 1][y] == GROUND && _map[x - 2][y] == WALL)) {
		tmp = std::make_pair(x - 1, y);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getFireText());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x - 1][y] = EXPLO;
	}
	else if ((_map[x - 1][y] == GROUND && _map[x - 2][y] == BRK) ||
		 (_map[x - 1][y] == GROUND && _map[x - 2][y] == GROUND)) {
		tmp = std::make_pair(x - 2, y);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getFireText());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		tmp = std::make_pair(x - 1, y);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getFireText());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x - 2][y] = EXPLO;
		_map[x - 1][y] = EXPLO;
	}
	if ((_map[x][y + 1] == BRK) || (_map[x][y + 1] == GROUND && _map[x][y + 2] == WALL)) {
		tmp = std::make_pair(x, y + 1);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getFireText());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x][y + 1] = EXPLO;
	}
	else if ((_map[x][y + 1] == GROUND && _map[x][y + 2] == BRK) ||
		 (_map[x][y + 1] == GROUND && _map[x][y + 2] == GROUND)) {
		tmp = std::make_pair(x, y + 2);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getFireText());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		tmp = std::make_pair(x, y + 1);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getFireText());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x][y + 2] = EXPLO;
		_map[x][y + 1] = EXPLO;
	}
	if ((_map[x][y - 1] == BRK) || (_map[x][y - 1] == GROUND && _map[x][y - 2] == WALL)) {
		tmp = std::make_pair(x, y - 1);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getFireText());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x][y - 1] = EXPLO;
	}
	else if ((_map[x][y - 1] == GROUND && _map[x][y - 2] == BRK) ||
		 (_map[x][y - 1] == GROUND && _map[x][y - 2] == GROUND)) {
		tmp = std::make_pair(x, y - 2);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getFireText());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		tmp = std::make_pair(x, y - 1);
		tmp_node = _ground[tmp];
		tmp_node->setMaterialTexture(0, _text->getFireText());
		node_pos = tmp_node->getPosition();
		node_pos.Z = INIT_Z - 30;
		tmp_node->setPosition(node_pos);
		_map[x][y - 2] = EXPLO;
		_map[x][y - 1] = EXPLO;
	}
	tmp = std::make_pair(x, y);
	tmp_node = _ground[tmp];
	tmp_node->setMaterialTexture(0, _text->getFireText());
	node_pos = tmp_node->getPosition();
	node_pos.Z = INIT_Z - 30;
	tmp_node->setPosition(node_pos);
	_map[x][y] = EXPLO;
	
	
}

void	Game::getBombEvents()
{
	if (_fisStarted) {
		_bombTEnd = std::chrono::system_clock::now();
		irr::s32	elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
			(_bombTEnd - _bombTStart).count();
		if (elapsed_seconds == 3 && _first != nullptr) {
			if (_bombNode != nullptr) {
				_data->sceneMngr->addToDeletionQueue(_bombNode);
				_bombNode = nullptr;
			}
			_stkX = _first->getSaveX();
			_stkY = _first->getSaveY();
			updateMapExp(_first->getSaveX(), _first->getSaveY());
			_fireTStart = std::chrono::system_clock::now();
			elapsed_seconds = 0;
			_fisStarted = false;
			_fireStarted = true;
		}
	}
	if (_sisStarted) {
		_sbombTEnd = std::chrono::system_clock::now();
		irr::s32	elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
			(_sbombTEnd - _sbombTStart).count();		
		if (elapsed_seconds == 3 && _second != nullptr) {
			if (_sbombNode != nullptr) {
				_data->sceneMngr->addToDeletionQueue(_sbombNode);
				_sbombNode = nullptr;
			}
			_saveX = _second->getSaveX();
			_saveY = _second->getSaveY();
			updateMapExp(_second->getSaveX(), _second->getSaveY());
			_sfireTStart = std::chrono::system_clock::now();
			elapsed_seconds = 0;
			_sisStarted = false;
			_sfireStarted = true;
		}
 
	}
	if (_fIaBombSted) {
		_fIaBombEnd = std::chrono::system_clock::now();
		irr::s32     elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
			(_fIaBombEnd - _fIaBombStart).count();
		if (elapsed_seconds == 3 && _firstIa != nullptr) {
			if (_iaFirstNode != nullptr)
				_data->sceneMngr->addToDeletionQueue(_iaFirstNode);
			_fIaBombX = _firstIa->getSaveX();
			_fIaBombY = _firstIa->getSaveY();
			updateMapExp(_firstIa->getSaveX(), _firstIa->getSaveY());
			_fiaFireStart = std::chrono::system_clock::now();
			elapsed_seconds = 0;
			_fIaBombSted = false;
			_fIaExploSted = true;
		}
	}
	if (_sIaBombSted) {
		_sIaBombEnd = std::chrono::system_clock::now();
		irr::s32     elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
			(_sIaBombEnd - _sIaBombStart).count();
		if (elapsed_seconds == 3 && _secondIa != nullptr) {
			if (_iaScdNode !=  nullptr)
				_data->sceneMngr->addToDeletionQueue(_iaScdNode);
			_sIaBombX = _secondIa->getSaveX();
			_sIaBombY = _secondIa->getSaveY();
			updateMapExp(_secondIa->getSaveX(), _secondIa->getSaveY());
			_siaFireStart = std::chrono::system_clock::now();
			elapsed_seconds = 0;
			_sIaBombSted = false;
			_sIaExploSted = true;
		}
	}
	if (_tIaBombSted) {
		_tIaBombEnd = std::chrono::system_clock::now();
		irr::s32     elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
			(_tIaBombEnd - _tIaBombStart).count();
		if (elapsed_seconds == 3 && _thirdIa != nullptr) {
			if (_iaThirdNode != nullptr)
				_data->sceneMngr->addToDeletionQueue(_iaThirdNode);
			_tIaBombX = _thirdIa->getSaveX();
			_tIaBombY = _thirdIa->getSaveY();
			updateMapExp(_thirdIa->getSaveX(), _thirdIa->getSaveY());
			_tiaFireStart = std::chrono::system_clock::now();
			elapsed_seconds = 0;
			_tIaBombSted = false;
			_tIaExploSted = true;
		}
	}
	
}

void	Game::getPlayerEvents()
{
	if (_first != nullptr) {
		if (_map[_first->getX()][_first->getY()] == EXPLO) {
			_data->sceneMngr->addToDeletionQueue(_first->getNode());
			_first = nullptr;
		}
	}
	if (_second != nullptr) {
		if (_map[_second->getX()][_second->getY()] == EXPLO) {
			_data->sceneMngr->addToDeletionQueue(_second->getNode());
			_second = nullptr;
		}
	}
	if (_firstIa != nullptr) {
		if (_map[_firstIa->getX()][_firstIa->getY()] == EXPLO) {
			_data->sceneMngr->addToDeletionQueue(_firstIa->getNode());
			_firstIa = nullptr;
		}
	}
	if (_secondIa != nullptr) {
		if (_map[_secondIa->getX()][_secondIa->getY()] == EXPLO) {
			_data->sceneMngr->addToDeletionQueue(_secondIa->getNode());
			_secondIa = nullptr;
		}
	}
	if (_thirdIa != nullptr) {
		if (_map[_thirdIa->getX()][_thirdIa->getY()] == EXPLO) {
			_data->sceneMngr->addToDeletionQueue(_thirdIa->getNode());
			_thirdIa = nullptr;
		}
	}
	
}

void	Game::getExploEvents()
{
	if (_fireStarted) {
		_fireTEnd = std::chrono::system_clock::now();
		irr::s32	elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
			(_fireTEnd - _fireTStart).count();
		if (elapsed_seconds == 1) {
			updateMap(_stkX, _stkY);
			elapsed_seconds = 0;
			_fireStarted = false;		
		}
	}
	if (_sfireStarted) {
		_sfireTEnd = std::chrono::system_clock::now();
		irr::s32	elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
			(_sfireTEnd - _sfireTStart).count();		
		if (elapsed_seconds == 1) {
			updateMap(_saveX, _saveY);
			elapsed_seconds = 0;
			_sfireStarted = false;
		}
 
	}
	if (_fIaExploSted) {
		_fiaFireEnd = std::chrono::system_clock::now();
		irr::s32     elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
			(_fiaFireEnd - _fiaFireStart).count();
		if (elapsed_seconds == 1) {
			updateMap(_fIaBombX, _fIaBombY);
			elapsed_seconds = 0;
			_fIaExploSted = false;
		}
	}
	if (_sIaExploSted) {
		_siaFireEnd = std::chrono::system_clock::now();
		irr::s32     elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
			(_siaFireEnd - _siaFireStart).count();
		if (elapsed_seconds == 1) {
			updateMap(_sIaBombX, _sIaBombY);
			elapsed_seconds = 0;
			_sIaExploSted = false;
		}
	}
	if (_tIaExploSted) {
		_tiaFireEnd = std::chrono::system_clock::now();
		irr::s32     elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
			(_tiaFireEnd - _tiaFireStart).count();
		if (elapsed_seconds == 1) {
			updateMap(_tIaBombX, _tIaBombY);
			elapsed_seconds = 0;
			_tIaExploSted = false;
		}
	}
}


void	Game::getGameEvents()
{
	if (_first != nullptr) {
		if (_gameEventRcv->isKeyDown(irr::KEY_KEY_C) && !_fisStarted)
			fdropBomb(_first);
		if (_gameEventRcv->isKeyDown(irr::KEY_KEY_Z))
			moveUpPlayer(_first);
		if (_gameEventRcv->isKeyDown(irr::KEY_KEY_Q))
			moveLeftPlayer(_first);
		if (_gameEventRcv->isKeyDown(irr::KEY_KEY_S))
			moveDownPlayer(_first);
		if (_gameEventRcv->isKeyDown(irr::KEY_KEY_D))
			moveRightPlayer(_first);
	}
	if (_second != nullptr) {
		if (_gameEventRcv->isKeyDown(irr::KEY_KEY_O))
			moveUpPlayer(_second);
		if (_gameEventRcv->isKeyDown(irr::KEY_KEY_K))
			moveLeftPlayer(_second);
		if (_gameEventRcv->isKeyDown(irr::KEY_KEY_L))
			moveDownPlayer(_second);
		if (_gameEventRcv->isKeyDown(irr::KEY_KEY_M))
			moveRightPlayer(_second);
		if (_gameEventRcv->isKeyDown(irr::KEY_KEY_N) && !_sisStarted)
			sdropBomb(_second);
	}
	if (_gameEventRcv->isKeyDown(irr::KEY_ESCAPE)) {
		_data->inGame = false;
		_data->quit = true;
	}
}

void    Game::findWayFia()
{
	if (!_fIaBombSted && !_fIaExploSted) {
		if ((_map[_firstIa->getX() + 1][_firstIa->getY()] == BRK) ||
		    (_map[_firstIa->getX() - 1][_firstIa->getY()] == BRK) ||
		    (_map[_firstIa->getX()][_firstIa->getY() + 1] == BRK) ||
		    (_map[_firstIa->getX()][_firstIa->getY() - 1] == BRK))
			fIaDropBomb();
		else
			moveIa(_firstIa);
	}
	else
		moveIaDodgeBomb(_firstIa);
}

void    Game::findWaySia()
{
	if (!_sIaBombSted && !_sIaExploSted) {
		if ((_map[_secondIa->getX() + 1][_secondIa->getY()] == BRK) ||
		    (_map[_secondIa->getX() - 1][_secondIa->getY()] == BRK) ||
		    (_map[_secondIa->getX()][_secondIa->getY() + 1] == BRK) ||
		    (_map[_secondIa->getX()][_secondIa->getY() - 1] == BRK))
			sIaDropBomb();
		else
			moveIa(_secondIa);
	}
	else
		moveIaDodgeBomb(_secondIa);
}

void    Game::findWayTia()
{
	if (!_tIaBombSted && !_tIaExploSted) {
		if ((_map[_thirdIa->getX() + 1][_thirdIa->getY()] == BRK) ||
		    (_map[_thirdIa->getX() - 1][_thirdIa->getY()] == BRK) ||
		    (_map[_thirdIa->getX()][_thirdIa->getY() + 1] == BRK) ||
		    (_map[_thirdIa->getX()][_thirdIa->getY() - 1] == BRK))
			tIaDropBomb();
		else
			moveIa(_thirdIa);
	}
	else
		moveIaDodgeBomb(_thirdIa);
}

void    Game::tIaDropBomb()
{
	if (!_tIaBombSted) {
		_fpBomb = _text->getBomb();
		_fpBombText = _text->getBombText();
		_tIaBombStart = std::chrono::system_clock::now();
		_iaThirdNode = _data->sceneMngr->addAnimatedMeshSceneNode(_fpBomb, 0, -1,
									  irr::core::vector3df(-520 + (60 * _thirdIa->getX()), -510 + (60 * _thirdIa->getY()), -540),
									  irr::core::vector3df(0, 0, 0),
									  irr::core::vector3df(1, 1, 1));
		_iaThirdNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_iaThirdNode->setMaterialTexture(0, _fpBombText);
		_thirdIa->setSaveX(_thirdIa->getX());
		_thirdIa->setSaveY(_thirdIa->getY());
		_tIaBombSted = true;
	}
}

void    Game::fIaDropBomb()
{
	if (!_fIaBombSted) {
		_fpBomb = _text->getBomb();
		_fpBombText = _text->getBombText();
		_fIaBombStart = std::chrono::system_clock::now();
		_iaFirstNode = _data->sceneMngr->addAnimatedMeshSceneNode(_fpBomb, 0, -1,
									  irr::core::vector3df(-520 + (60 * _firstIa->getX()), -510 + (60 * _firstIa->getY()), -540),
									  irr::core::vector3df(0, 0, 0),
									  irr::core::vector3df(1, 1, 1));
		_iaFirstNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_iaFirstNode->setMaterialTexture(0, _fpBombText);
		_firstIa->setSaveX(_firstIa->getX());
		_firstIa->setSaveY(_firstIa->getY());
		_fIaBombSted = true;
	}
}

void    Game::sIaDropBomb()
{
	if (!_sIaBombSted) {
		_fpBomb = _text->getBomb();
		_fpBombText = _text->getBombText();
		_sIaBombStart = std::chrono::system_clock::now();
		_iaScdNode = _data->sceneMngr->addAnimatedMeshSceneNode(_fpBomb, 0, -1,
									irr::core::vector3df(-520 + (\
												     60 * _secondIa->getX()), -510 + (60 * _secondIa->getY()), -540),
									irr::core::vector3df(0, 0, 0)\
									,
									irr::core::vector3df(1, 1, 1)\
			);
		_iaScdNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_iaScdNode->setMaterialTexture(0, _fpBombText);
		_secondIa->setSaveX(_secondIa->getX());
		_secondIa->setSaveY(_secondIa->getY());
		_sIaBombSted = true;
	}
}

void    Game::getIaEvents()
{
	if (_firstIa != nullptr) {
		findWayFia();
	}
	if (_secondIa != nullptr)
		findWaySia();
	if (_thirdIa != nullptr) {
		findWayTia();
	}
}

void    Game::moveIa(Ia *ia)
{
	irr::s32        my_rand = 0;
	irr::s32        can_go = 0;

	srand(time(NULL));
	my_rand = rand() % 4 + 1;
	switch (my_rand) {
	case 1:
		if (_map[ia->getX() + 1][ia->getY()] == GROUND)
			ia->setPosition(ia->getX() + 1, ia->getY(), -540);
		else if (_map[ia->getX() - 1][ia->getY()] == GROUND)
			ia->setPosition(ia->getX() - 1, ia->getY(), -540);
		else if (_map[ia->getX()][ia->getY() + 1] == GROUND)
			ia->setPosition(ia->getX(), ia->getY() + 1, -540);
		else if (_map[ia->getX()][ia->getY() - 1] == GROUND)
			ia->setPosition(ia->getX(), ia->getY() - 1, -540);
		break;
	case 2:
		if (_map[ia->getX() - 1][ia->getY()] == GROUND)
			ia->setPosition(ia->getX() - 1, ia->getY(), -540);
		else if (_map[ia->getX()][ia->getY() + 1] == GROUND)
			ia->setPosition(ia->getX(), ia->getY() + 1, -540);
		else if (_map[ia->getX()][ia->getY() - 1] == GROUND)
			ia->setPosition(ia->getX(), ia->getY() - 1, -540);
		else if (_map[ia->getX() + 1][ia->getY()] == GROUND)
			ia->setPosition(ia->getX() + 1, ia->getY(), -540);
		break;
	case 3:
		if (_map[ia->getX()][ia->getY() + 1] == GROUND)
			ia->setPosition(ia->getX(), ia->getY() + 1, -540);
		else if (_map[ia->getX()][ia->getY() - 1] == GROUND)
			ia->setPosition(ia->getX(), ia->getY() - 1, -540);
		else if (_map[ia->getX() + 1][ia->getY()] == GROUND)
			ia->setPosition(ia->getX() + 1, ia->getY(), -540);
		else if (_map[ia->getX() - 1][ia->getY()] == GROUND)
			ia->setPosition(ia->getX() - 1, ia->getY(), -540);
		break;
	case 4:
		if (_map[ia->getX()][ia->getY() - 1] == GROUND)
			ia->setPosition(ia->getX(), ia->getY() - 1, -540);
		else if (_map[ia->getX() + 1][ia->getY()] == GROUND)
			ia->setPosition(ia->getX() + 1, ia->getY(), -540);
		else if (_map[ia->getX() - 1][ia->getY()] == GROUND)
			ia->setPosition(ia->getX() - 1, ia->getY(), -540);
		else if (_map[ia->getX()][ia->getY() + 1] == GROUND)
			ia->setPosition(ia->getX(), ia->getY() + 1, -540);
		break;
	default:
		break;
	}
	return;
}

void    Game::moveIaDodgeBomb(Ia *ia)
{
	int     can_move_y = 0;
	int     can_move_x = 0;

	if (ia->getX() == ia->getSaveX() && ia->getY() == ia->getSaveY()) {
		moveIaFromBomb(ia);
		return;
	}
	else if (ia->getX() - 1 == ia->getSaveX() && ia->getY() == ia->getSaveY()) {
		if ((can_move_y = moveIaY(ia)) == 1) {
			if ((can_move_x = moveIaUpX(ia)) == 1)
				moveIaDownX(ia);
		}
		return;
	}
	else if (ia->getX() + 1 == ia->getSaveX() && ia->getY() == ia->getSaveY()) {
		if ((can_move_y = moveIaY(ia)) == 1)
			if ((can_move_x = moveIaDownX(ia)) == 1)
				moveIaUpX(ia);
		return;
	}
	else if (ia->getX() == ia->getSaveX() && ia->getY() + 1 == ia->getSaveY()) {
		if ((can_move_x = moveIaX(ia)) == 1)
			if ((can_move_y = moveIaDownY(ia)) == 1)
				moveIaUpY(ia);
		return;
	}
	else if (ia->getX() + 1 == ia->getSaveX() && ia->getY() - 1 == ia->getSaveY()) {
		if ((can_move_x = moveIaX(ia)) == 1)
			if ((can_move_y = moveIaUpY(ia)) == 1)
				moveIaDownY(ia);
		return;
	}
	else if (ia->getX() - 2 == ia->getSaveX() && ia->getY() == ia->getSaveY()) {
		if ((can_move_y = moveIaY(ia)) == 1)
			if ((can_move_x = moveIaUpX(ia)) == 1)
				moveIaDownX(ia);
		return;
	}
	else if (ia->getX() + 2 == ia->getSaveX() && ia->getY() == ia->getSaveY()) {
		if ((can_move_y = moveIaY(ia)) == 1)
			if ((can_move_x = moveIaDownX(ia)) == 1)
				moveIaUpX(ia);
		return;
	}
	else if (ia->getX() == ia->getSaveX() && ia->getY() + 2 == ia->getSaveY()) {
		if ((can_move_x = moveIaX(ia)) == 1)
			if ((can_move_y = moveIaDownY(ia)) == 1)
				moveIaUpY(ia);
		return;
	}
	else if (ia->getX() == ia->getSaveX() && ia->getY() - 2 == ia->getSaveY()) {
		if ((can_move_x = moveIaX(ia)) == 1)
			if ((can_move_y = moveIaUpY(ia)) == 1)
				moveIaDownY(ia);
		return;
	}
	return;

}

void    Game::moveIaFromBomb(Ia *ia)
{
	int     i;

	if ((_map[ia->getX() + 1][ia->getY()] == GROUND)) {
		ia->setPosition(ia->getX() + 1, ia->getY(), -540);
		return;
	}
	else if ((_map[ia->getX() - 1][ia->getY()] == GROUND)) {
		ia->setPosition(ia->getX() - 1, ia->getY(), -540);
		return;
	}
	else if ((_map[ia->getX()][ia->getY() + 1] == GROUND)) {
		ia->setPosition(ia->getX(), ia->getY() + 1, -540);
		return;
	}
	else if ((_map[ia->getX()][ia->getY() - 1] == GROUND)) {
		ia->setPosition(ia->getX(), ia->getY() - 1, -540);
		return;
	}
	else
		return;
}

int     Game::moveIaY(Ia *ia)
{
	if (_map[ia->getX()][ia->getY() - 1] == GROUND) {
		ia->setPosition(ia->getX(), ia->getY() - 1, -540);
		return 0;
	}
	else if (_map[ia->getX()][ia->getY() + 1] == GROUND) {
		ia->setPosition(ia->getX(), ia->getY() + 1, -540);
		return 0;
	}
	return 1;
}

int     Game::moveIaX(Ia *ia)
{
	if (_map[ia->getX() - 1][ia->getY()] == GROUND) {
		ia->setPosition(ia->getX() - 1, ia->getY(), -540);
		return 0;
	}
	else if (_map[ia->getX() + 1][ia->getY()] == GROUND) {
		ia->setPosition(ia->getX() + 1, ia->getY(), -540);
		return 0;
	}
	return 1;
}

int     Game::moveIaUpX(Ia *ia)
{
	if (_map[ia->getX() + 1][ia->getY()] == GROUND) {
		ia->setPosition(ia->getX() + 1, ia->getY(), -540);
		return 0;
	}
	return 1;
}

int     Game::moveIaDownX(Ia *ia)
{
	if (_map[ia->getX() - 1][ia->getY()] == GROUND) {
		ia->setPosition(ia->getX() - 1, ia->getY(), -540);
		return 0;
	}
	return 1;
}

int     Game::moveIaDownY(Ia *ia)
{
	if (_map[ia->getX()][ia->getY() - 1] == GROUND) {
		ia->setPosition(ia->getX(), ia->getY() - 1, -540);
		return 0;
	}
	return 1;
}

int     Game::moveIaUpY(Ia *ia)
{
	if (_map[ia->getX()][ia->getY() + 1] == GROUND) {
		ia->setPosition(ia->getX(), ia->getY() + 1, -540);
		return 0;
	}
	return 1;
}

bool	Game::Win()
{
	if (_first != nullptr && _second == nullptr && _firstIa == nullptr &&
	    _secondIa == nullptr && _thirdIa == nullptr) {
		deleteNodesPlayer(_first);
		_data->winType = P1WIN;
		return true;
	}
	if (_first == nullptr && _second != nullptr && _firstIa == nullptr &&
	    _secondIa == nullptr && _thirdIa == nullptr) {
		deleteNodesPlayer(_second);
		_data->winType = P2WIN;
		return true;
	}
	if ((_first == nullptr && _second == nullptr) && (_firstIa != nullptr ||
							  _secondIa != nullptr ||
							  _thirdIa != nullptr)) {
		std::cout << "-------------is WIN----------\n";
		deleteNodesIa();
		_data->winType = IAWIN;
		return true;
	}
	return false;
}

void	Game::deleteNodesPlayer(Character *character)
{
	if (character != nullptr) {
		if (_bombNode != nullptr) {
			std::cout << "deleteBomb Node\n";
			_data->sceneMngr->addToDeletionQueue(_bombNode);
			std::cout << "deleteBomb Node\n";
		}
		if (_sbombNode != nullptr)
			std::cout << "deletesBomb Node\n";
			_data->sceneMngr->addToDeletionQueue(_sbombNode);
			std::cout << "deleteSBomb Node\n";
		delete character;
	}
	deleteMapNodes();
	_map.clear();
}

void	Game::deleteNodesIa()
{
	if (_firstIa != nullptr) {
		if (_iaFirstNode != nullptr) {
			std::cout << "delete iaFirstNode\n";
			_data->sceneMngr->addToDeletionQueue(_iaFirstNode);
			std::cout << "delete iaFirstNode\n";
		}
		delete _firstIa;
	}
	if (_secondIa != nullptr) {
		if (_iaScdNode != nullptr) {
			std::cout << "delete iaScdNode\n";
			_data->sceneMngr->addToDeletionQueue(_iaScdNode);
			std::cout << "delete iaScdNode\n";
		}
		delete _secondIa;
	}
	if (_thirdIa != nullptr) {
		if (_iaThirdNode != nullptr)
			std::cout << "delete iaThirdNode\n";
			_data->sceneMngr->addToDeletionQueue(_iaFirstNode);
			std::cout << "delete iaThirdNode\n";
		delete _thirdIa;
	}
	deleteMapNodes();
	_map.clear();
}

void	Game::deleteMapNodes()
{
	std::pair<int, int>	tmp_pos;
	irr::s32 i = 0;
	irr::s32 j = 0;
	
	for (irr::s32 i = 0; i < _map.size(); i++)
	{
		for (irr::s32 j = 0; j < _map[i].size(); j++)
		{
			tmp_pos = std::make_pair(i, j);
			if (_ground[tmp_pos] != nullptr)
				_data->sceneMngr->addToDeletionQueue(_ground[tmp_pos]);
		}
		j = 0;
	}
}

void	Game::drawMap()
{
	_data->sceneMngr->addCameraSceneNode(0, irr::core::vector3df(110, 0, 450),
					     irr::core::vector3df(110, 0, -400));
	makeMap();
	while (_data->device->run() && _data->inGame == true && Win() == false) {
		_data->driver->beginScene(true, true, irr::video::SColor(255, 102, 102, 136));
		getBombEvents();
		getPlayerEvents();
		getExploEvents();
		getGameEvents();
		getIaEvents();
		_data->sceneMngr->drawAll();
		_data->driver->endScene();
	}
	return;
}

void	Game::createCharacters()
{
	_first = new Character(_text->getFirstPlayer(), _text->getCharacterMesh(), 1, 1, RIGHT);
	_first->setClass(_data);
	_first->createNode();
	_first->setRotation(1);
	_firstIa = new Ia(_text->getIa(), _text->getCharacterMesh(), 1, 18, LEFT);
	_firstIa->setClass(_data);
	_firstIa->createNode();
	_secondIa = new Ia(_text->getIa(), _text->getCharacterMesh(), 18, 1, RIGHT);
	_secondIa->setClass(_data);
	_secondIa->createNode();
	if (_data->nbPlayers == 2) {
		_second = new Character(_text->getSecondPlayer(), _text->getCharacterMesh(), 18, 18, LEFT);
		_second->setClass(_data);
		_second->createNode();
		_second->setRotation(3);
		_thirdIa = nullptr;
	} else if (_data->nbPlayers == 1) {
		_thirdIa = new Ia(_text->getIa(), _text->getCharacterMesh(), 18, 18, LEFT);
		_thirdIa->setClass(_data);
		_thirdIa->createNode();
		_second = nullptr;
	}
}
;
