/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:02:43 by mleibeng          #+#    #+#             */
/*   Updated: 2024/02/29 13:42:17 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int	main(void)
{
	Zombie *FirstZombie;
	FirstZombie = newZombie("Johnny");
	FirstZombie->announce();
	randomChump("Edgar");
	delete FirstZombie;
	return (0);
}