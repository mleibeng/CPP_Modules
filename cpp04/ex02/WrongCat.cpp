/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:54:08 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/11 23:10:45 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	type = "WrongCat";
	std::cout << "Constructed WrongCat " << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	if (this != &copy)
		type = copy.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << " deconstructed" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "hee-haw!" << std::endl;
}

std::string WrongCat::getType() const
{
	return type;
}