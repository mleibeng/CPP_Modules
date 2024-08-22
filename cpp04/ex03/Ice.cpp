/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:59:18 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/04 00:04:05 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice Constructor called" << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria(copy)
{
	// std::cout << "Ice Copy Constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &copy)
{
	if (this != &copy)
		AMateria::operator=(copy);
	return(*this);
}

Ice *Ice::clone() const
{
	return new Ice(*this);
}

std::string const &Ice::getType() const
{
	return AMateria::getType();
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
	//std::cout << "Ice destructed" << std::endl;
}
