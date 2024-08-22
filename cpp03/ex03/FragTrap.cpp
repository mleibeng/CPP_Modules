/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:07:02 by mleibeng          #+#    #+#             */
/*   Updated: 2024/08/22 17:04:30 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap::ClapTrap()
{
	this->name = "unknown";
	this->HitPoints = 100;
	this->AttackDamage = 30;
	std::cout << "Constructed FragTrap " << name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->AttackDamage = 30;
	std::cout << "FragTrap " << name << " is creating its body" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->HitPoints = copy.HitPoints;
		this->EnergyPoints = copy.EnergyPoints;
		this->AttackDamage = copy.AttackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is in self-destruct" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " is asking for a high five yeah!!" << std::endl;
}
