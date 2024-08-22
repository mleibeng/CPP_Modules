/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:45:38 by mleibeng          #+#    #+#             */
/*   Updated: 2024/05/24 21:51:47 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	type = "Animal";
	std::cout << "Constructed Animal " << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
	if (this != &copy)
		type = copy.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal " << " deconstructed" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "random animal noises" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}