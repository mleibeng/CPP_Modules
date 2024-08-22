/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:30:44 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/06 04:58:16 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &newname, Weapon &weapontype) : myWeapon(weapontype), name(newname) {}

void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << myWeapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << name << " deleted" << std::endl;
}