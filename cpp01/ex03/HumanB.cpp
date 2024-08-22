/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUmanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:30:48 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/06 05:48:50 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &newName) : myWeapon(),  name(newName) {}

void HumanB::setWeapon(Weapon &newWeapon)
{
	myWeapon = &newWeapon;
}

void HumanB::attack() const
{
	if (myWeapon != NULL)
		std::cout << name << " attacks with their " << myWeapon->getType() << std::endl;
	else
		std::cout << name << " attacks with their arms " << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "deleted " << name << std::endl;
}