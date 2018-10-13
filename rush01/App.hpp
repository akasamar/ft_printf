/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:54:04 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/13 16:17:06 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_APP_HPP
#define RUSH01_APP_HPP

//#include "SDL.h"
#include <iostream>
//#include "Ncurse.hpp"

class App
{
public:
	App();
	App(const App &other);
	App &operator= (const App &other);
	~App();

	bool 	init();
	int 	exegute();
	virtual void	getEvent() = 0;
	virtual void	loop() = 0;
	virtual void	render() = 0;
	void	cleanup();

protected:
	bool 	_running;
};

#endif //RUSH01_APP_HPP
