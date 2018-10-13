/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:54:47 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/13 16:17:06 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "App.hpp"

App::App()
{
}

App &App::operator=(const App &other) {
	if (this != &other)
	{
		//copy stuff
	}
	return *this;
}

App::App(const App &other)
{
	*this = other;
}

App::~App()
{

}

bool App::init()
{
	_running = true;
	//Init stuff for ncurses

	//init stuff for SDL
	return true;
}

int App::exegute() {
	if (!(init()))
		return -1;

	while (_running)
	{
		getEvent();
		loop();
		render();
	}

	cleanup();
	return 0;
}

void App::cleanup() {

}

