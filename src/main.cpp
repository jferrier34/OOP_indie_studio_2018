/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** main
*/

#include "../inc/Core.hpp"

irr::s32	main(irr::s32 ac, irr::c8 **av, irr::c8 **env)
{
	Core Core;

	if (env == NULL)
		return (84);
	Core.mainLoop();
	return 0;
}
