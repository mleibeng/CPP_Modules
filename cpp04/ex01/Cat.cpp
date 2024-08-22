/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:54:08 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/03 23:19:40 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	brain = new Brain();
	type = "Cat";
	std::cout << "Constructed Cat " << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	brain = new Brain(*(copy.brain));
	std::cout << "Cat copy constructed" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		type = copy.type;
		delete brain;
		brain = new Brain(*(copy.brain));
	}
	std::cout << "assigned cat copy" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat " << " deconstructed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

std::string Cat::getType() const
{
	return type;
}

void Cat::setBrainIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const
{
	if (index >= 0 && index < 100)
			return std::string(brain->getIdea(index));
		else
			return "";
}