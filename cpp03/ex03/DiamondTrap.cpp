/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:30:35 by mleibeng          #+#    #+#             */
/*   Updated: 2024/08/22 17:02:58 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap::ClapTrap(), ScavTrap::ScavTrap(), FragTrap::FragTrap()
{
	this->name = "unknown";
	HitPoints = FragTrap::HitPoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDamage = FragTrap::AttackDamage;
	std::cout << "Constructed FragTrap " << name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	this->ClapTrap::name = name + "_clap_name";
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;
	std::cout << "Diamond " << name << " called into existence" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " burned up" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
	}
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << this->name << " and  ClapTrap " << ClapTrap::name << " with " << this->HitPoints << "HP, " << this->EnergyPoints << "EP, and " << this->AttackDamage << " attack" << std::endl;
}
