/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:56:37 by mleibeng          #+#    #+#             */
/*   Updated: 2024/06/01 20:25:31 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

typedef void (Harl::*MemberFuncPtr)();

Harl::Harl() {}

void Harl::debug()
{
	std::cout << "Somewhere, somehow, somewhat you are looking for something" << std::endl;
}

void Harl::info()
{
	std::cout << "Ye this is to tell you, you give me some values, i give you some data" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think you fucked up somewhere" << std::endl;
}

void Harl::error()
{
	std::cout << "Oh look, big pro at work, except that you can be happy the PC didnt delete itself out of shame for having to try to execute your shipwreck of a code." << std::endl;
}

// void Harl::complain(std::string level)
// {
// 	void (Harl::*complaintFunc)();

// 	if (level == "debug")
// 	{
// 		complaintFunc = &Harl::debug;
// 		(this->*complaintFunc)();
// 	}
// 	if (level == "info")
// 	{
// 		complaintFunc = &Harl::info;
// 		(this->*complaintFunc)();
// 	}
// 	if (level == "warning")
// 	{
// 		complaintFunc = &Harl::warning;
// 		(this->*complaintFunc)();
// 	}
// 	if (level == "error")
// 	{
// 		complaintFunc = &Harl::error;
// 		(this->*complaintFunc)();
// 	}
// }

Harl::~Harl() {}

// in case someone doesnt like my if statements:
void Harl::complain(std::string level)
{
	void (Harl::*complaintFunc)();
	switch (level.c_str()[0])
{
		case 'd':
			if (level == "debug")
			{
				complaintFunc = &Harl::debug;
				(this->*complaintFunc)();
			}
			break;
		case 'i':
			if (level == "info")
			{
				complaintFunc = &Harl::info;
				(this->*complaintFunc)();
			}
			break;
		case 'w':
			if (level == "warning")
			{
				complaintFunc = &Harl::warning;
				(this->*complaintFunc)();
			}
			break;
		case 'e':
			if (level == "error")
			{
				complaintFunc = &Harl::error;
				(this->*complaintFunc)();
			}
			break;
		default:
			break;
	}
}