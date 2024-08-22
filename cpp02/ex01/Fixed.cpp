/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:14:16 by mleibeng          #+#    #+#             */
/*   Updated: 2024/06/09 20:02:44 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractBits = 8;
const float FLOAT_MAX = 3.40282347e+38f;

Fixed::Fixed()
{
	fixedValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intie)
{
	std::cout << "Int constructor called" << std::endl;
	if (intie > (INT_MAX >> Fixed::fractBits))
		std::cout << "Int too high for conversion" << std::endl;
	else
		this->fixedValue = intie << Fixed::fractBits;
}

Fixed::Fixed(const float floatie)
{
	std::cout << "Float constructor called" << std::endl;
	if (floatie > roundf(FLOAT_MAX / (1 << Fixed::fractBits)))
		std::cout << "Input float too big for conversion into fixpoint numbers" << std::endl;
	else
		this->fixedValue = roundf(floatie * (1 << Fixed::fractBits));
}
float Fixed::toFloat() const
{
	return (static_cast<float>(fixedValue) / (1 << Fixed::fractBits));
}

int	Fixed::toInt() const
{
	return (fixedValue >> fractBits);
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->fixedValue = copy.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	return (fixedValue);
}

void Fixed::setRawBits(int const raw)
{
	fixedValue = raw;
}

std::ostream &operator<<(std::ostream &outstream, const Fixed& member)
{
	outstream << member.toFloat();
	return outstream;
}