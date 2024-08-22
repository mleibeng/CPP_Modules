/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:03:24 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/06 00:37:01 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie *ZombieHorde(int N, std::string name)
{
	int i;
	Zombie* Zombiemates = new Zombie[N];
	i = -1;
	while (++i < N)
		Zombiemates[i] = Zombie(name);
	return (Zombiemates);
}