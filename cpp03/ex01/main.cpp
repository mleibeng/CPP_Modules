/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:09:06 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/11 19:05:35 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap John2("John2");

	John2.attack("Bobby");
	John2.beRepaired(12);
	John2.takeDamage(12);
	John2.guardGate();
	return (0);
}