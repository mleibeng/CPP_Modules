/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:09:38 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/11 22:07:15 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "unknown";
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
	std::cout << "Constructed ClapTrap " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
	std::cout << "Constructed ClapTrap " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
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

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " deconstructed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	EnergyPoints--;
	if (EnergyPoints >= 0)
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
	else
		std::cout << "ClapTrap " << name << " is too tired to attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	HitPoints -= amount;
	if (HitPoints > 0)
		std::cout << "ClapTrap " << name << " has taken " << amount << " HitPoints of damage, he currently has " << HitPoints << " left!" << std::endl;
	else
	{
		EnergyPoints = -1;
		std::cout << "ClapTrap " << name << " has taken too much damage and cannot continue!!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	EnergyPoints--;
	if (EnergyPoints >= 0)
	{
		HitPoints += amount;
		std::cout << "ClapTrap " << name << " was repaired by " << amount << " and now has " << HitPoints << "HP" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " cannot be repaired because it has no more Energy!!" << std::endl;
}