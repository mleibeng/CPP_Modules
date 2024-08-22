/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:30:56 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/06 05:34:36 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &weaponType) : type(weaponType) {}

const std::string &Weapon::getType() const
{
	return (type);
}

void Weapon::setType(const std::string &weapontype)
{
	type = weapontype;
}

Weapon::~Weapon()
{
	std::cout << "Weapon " << type << " deleted" << std::endl;
}