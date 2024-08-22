/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:45:38 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/03 23:35:35 by mleibeng         ###   ########.fr       */
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
	std::cout << "Animal deconstructed" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}