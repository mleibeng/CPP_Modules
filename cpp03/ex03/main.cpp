/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:09:06 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/11 20:35:44 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap John4("John4");
	John4.whoAmI();
	John4.takeDamage(20);
	John4.attack("target");
	John4.guardGate();
	John4.highFivesGuys();

	return (0);
}