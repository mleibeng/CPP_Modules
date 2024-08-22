/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:02:43 by mleibeng          #+#    #+#             */
/*   Updated: 2024/05/28 20:58:16 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int	main(void)
{
	int	i;
	Zombie *Zombies;
	Zombies = ZombieHorde(5 ,"Johnny");

	i = 0;
	while (i < 5)
	{
		Zombies[i].announce();
		i++;
	}
	delete[] Zombies;
	return (0);
}