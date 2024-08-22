/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:54:13 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/03 23:30:25 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	brain = new Brain();
	type = "Dog";
	std::cout << "Constructed Dog " << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	brain = new Brain(*(copy.brain));
	std::cout << "Dog copy constructed" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		type = copy.type;
		delete brain;
		brain = new Brain (*(copy.brain));
	}
	std::cout << "assigned dog copy" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog " << " deconstructed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

std::string Dog::getType() const
{
	return type;
}

void Dog::setBrainIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const
{
	if (index >= 0 && index < 100)
			return std::string(brain->getIdea(index));
		else
			return "";
}