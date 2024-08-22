/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:03:15 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/06 00:35:16 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class Zombie
{
	private:
	std::string name;

	public:

	Zombie();
	Zombie(std::string name);

	void	announce(void);
	~Zombie();
};

Zombie* ZombieHorde(int N, std::string name);
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif