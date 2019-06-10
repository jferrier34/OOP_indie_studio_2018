//
// EPITECH PROJECT, 2018
// OOP_indie_studio_2018
// File description:
// MenuEventReceiver.hpp
//

#ifndef MENU_EVENT_RECEIVER_HPP_
#define MENU_EVENT_RECEIVER_HPP_

#include "Globals.hpp"

class MenuEventReceiver : public irr::IEventReceiver {
public:
	MenuEventReceiver();
	bool	OnEvent(const irr::SEvent &event);
	void	setClass(t_global_data *data);
	void	set_coordonate(bool direction);
	void	parse_cmd();
private:
	t_global_data	*_data;
};

#endif
