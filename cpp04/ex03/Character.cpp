/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:39:23 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/04 01:54:13 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for(int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		createdMaterias[i] = NULL;
	this->name = "Unknown";
	this->num_of_items = 0;
}

Character::Character(std::string const &name)
{
	for(int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		createdMaterias[i] = NULL;
	this->name = name;
	this->num_of_items = 0;
}

Character::Character(const Character &copy)
{
	this->name = copy.name;
	this->num_of_items = copy.num_of_items;
	for (int i = 0; i < 4; ++i)
	{
		if (copy.inventory[i] != NULL)
			inventory[i] = copy.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	for (int i = 0; i < num_of_items; ++i)
	{
		if (copy.createdMaterias[i] != NULL)
			createdMaterias[i] = copy.createdMaterias[i]->clone();
		else
			createdMaterias[i] = NULL;
	}
	for (int i = num_of_items; i < 100; ++i)
		createdMaterias[i] = NULL;
}

Character &Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		name = copy.name;
		num_of_items = copy.num_of_items;
		for (int i = 0; i < 4; ++i)
		{
			if (inventory[i] != NULL)
			{
				delete inventory[i];
				inventory[i] = NULL;
			}
		}
		for (int i = 0; i < num_of_items; ++i)
		{
			if (createdMaterias[i] != NULL)
			{
				delete createdMaterias[i];
				createdMaterias[i] = NULL;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			if (copy.inventory[i] != NULL)
				inventory[i] = copy.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		for (int i = 0; i < num_of_items; ++i)
		{
			if (copy.createdMaterias[i] != NULL)
				createdMaterias[i] = copy.createdMaterias[i]->clone();
			else
				createdMaterias[i] = NULL;
		}
		for (int i = num_of_items; i < 100; ++i)
			createdMaterias[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
	for (int i = 0; i < num_of_items; ++i)
	{
		if (createdMaterias[i] != NULL)
		{
			delete createdMaterias[i];
			createdMaterias[i] = NULL;
		}
	}
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria *m)
{
	for(int i = 0; i < 4; ++i)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		if (num_of_items < 100)
		{
			createdMaterias[num_of_items++] = inventory[idx];
			inventory[idx] = NULL;
		}
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
		inventory[idx]->use(target);
}