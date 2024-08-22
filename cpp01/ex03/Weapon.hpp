/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:30:29 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/06 04:07:53 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>


class Weapon
{
	private:
	std::string	type;

	public:
	Weapon(const std::string &weaponType);

	const std::string &getType() const;
	void setType(const std::string &weapontype);
	~Weapon();
};

#endif