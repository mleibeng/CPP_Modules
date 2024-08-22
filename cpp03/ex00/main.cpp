/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:09:06 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/01 23:46:57 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap John("John");
	ClapTrap Bobby;

	John.attack("Bobby");
	John.attack("Bobby");
	John.attack("Bobby");
	John.attack("Bobby");
	John.attack("Bobby");
	John.attack("Bobby");
	John.attack("Bobby");
	John.beRepaired(12);
	John.attack("Bobby");
	John.attack("Bobby");
	John.takeDamage(12);
	John.takeDamage(12);
	John.attack("Bobby");
	John.beRepaired(15);
	Bobby.attack("John");
	return (0);
}