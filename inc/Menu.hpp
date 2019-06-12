//
// EPITECH PROJECT, 2018
// Indie Studio
// File description:
// Header file of the Menu class
//

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Globals.hpp"

enum BUTTON {
	ID_BUTTON_EXIT = 100,
	ID_BUTTON_SAVE = 101,
	ID_BUTTON_PLAYER = 102,
	ID_BUTTON_LINE = 103
};

class Menu {
public:
	Menu();
	~Menu() = default;
	void			initTextures();
	void			drawFirstScreen();
	void			drawRealMenu();
	irr::s32			drawSettings();
	irr::gui::IGUIButton	*getExitButton() const;
	irr::gui::IGUIButton	*getSaveButton() const;
	void			setClass(t_global_data data);	
	void			drawP1Win();
	void			drawP2Win();
	void			drawAIWin();
private:
	t_global_data			_data;
	irr::video::ITexture		*_firstScreen;
	irr::video::ITexture		*_menuImg;
	irr::video::ITexture		*_menuSelector;
	irr::video::ITexture		*_menuSettings;
	irr::video::ITexture		*_p1Win;
	irr::video::ITexture		*_p2Win;
	irr::video::ITexture		*_AIWin;
	irr::gui::IGUIButton		*exitButton;
        irr::gui::IGUIButton		*saveButton;
	irr::gui::IGUIButton		*playerButton;
	irr::gui::IGUIButton		*mute;
	irr::gui::IGUIButton		*line;
	bool				_isFirstScreen;
};

#endif