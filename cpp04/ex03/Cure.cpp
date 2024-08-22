/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:59:34 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/03 23:55:06 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure Constructor called" << std::endl;
}

Cure::Cure(const Cure& copy) : AMateria(copy)
{
	// std::cout << "Cure Copy Constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &copy)
{
	if (this != &copy)
		AMateria::operator=(copy);
	return(*this);
}

Cure *Cure::clone() const
{
	return new Cure(*this);
}

std::string const &Cure::getType() const
{
	return AMateria::getType();
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure()
{
	//std::cout << "Cure destructed" << std::endl;
}
