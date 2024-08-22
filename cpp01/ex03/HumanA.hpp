/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:30:46 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/06 04:57:38 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
	private:
	Weapon &myWeapon;
	std::string name;

	public:
	HumanA(const std::string &name, Weapon &weapontype);

	void attack() const;

	~HumanA();
};

#endif