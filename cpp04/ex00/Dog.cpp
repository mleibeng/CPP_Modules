/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:54:13 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/03 21:14:46 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
	std::cout << "Constructed Dog " << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
		type = copy.type;
	return (*this);
}

Dog::~Dog()
{
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