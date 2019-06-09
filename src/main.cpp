//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// main.cpp
//

#include "../inc/Core.hpp"

irr::s32	main(irr::s32 ac, irr::c8 **av, irr::c8 **env)
{
	Core Core;

	if (env == NULL)
		return (84);
	Core.mainLoop();
	return 0;
}
