/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:16:19 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/02 00:01:26 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap::ClapTrap()
{
	this->name = "unknown";
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap " << name << " was created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap " << name << " was created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
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

void ScavTrap::attack(const std::string &target)
{
	EnergyPoints--;
	if (EnergyPoints >= 0)
		std::cout << "ScavTrap " << name << " bombards " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
	else
		std::cout << "ScavTrap " << name << " is way too tired to attack" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " absolutely annihilated" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
void ScavTrap::takeDamage( unsigned int amount)
{
	ClapTrap::takeDamage(amount);
}

void ScavTrap::beRepaired( unsigned int amount)
{
	ClapTrap::beRepaired(amount);
}