/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:30:50 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/06 05:45:23 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
	private:
	Weapon *myWeapon;
	std::string name;

	public:
	HumanB(const std::string &name);

	void attack() const;
	void setWeapon(Weapon &newWeapon);

	~HumanB();
};

#endif