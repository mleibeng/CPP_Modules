/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:56:37 by mleibeng          #+#    #+#             */
/*   Updated: 2024/06/01 21:38:14 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "Somewhere, somehow, somewhat you are looking for something" << std::endl << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Ye this is to tell you, you give me some values, i give you some data" << std::endl << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think you fucked up somewhere" << std::endl << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Oh look, big pro at work, except that you can be happy the PC didnt delete itself out of shame for having to try to execute your shipwreck that you call code." << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
	int i;

	i = 0;
	if (level == "DEBUG" || level == "debug")
		i = 1;
	if (level == "info" || level == "INFO")
		i = 2;
	if (level == "warning" || level == "WARNING")
		i = 3;
	if (level == "error" || level == "ERROR")
		i = 4;

	switch(i)
	{
		case 4:
			(this->*(&Harl::error))();
			break ;
		case 3:
		{
			(this->*(&Harl::warning))();
			(this->*(&Harl::error))();
			break;
		}
		case 2:
		{
			(this->*(&Harl::info))();
			(this->*(&Harl::warning))();
			(this->*(&Harl::error))();
			break ;
		}
		case 1:
		{
			(this->*(&Harl::debug))();
			(this->*(&Harl::info))();
			(this->*(&Harl::warning))();
			(this->*(&Harl::error))();
			break ;
		}
		default:
			std::cout << "I just turned it off because its annoying, like a dog that wont stop barking or a crying child" << std::endl;
			break ;
	}
}

Harl::~Harl() {}