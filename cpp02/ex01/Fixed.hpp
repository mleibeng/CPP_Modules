/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:14:21 by mleibeng          #+#    #+#             */
/*   Updated: 2024/06/04 22:24:50 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>
#include <limits>

class Fixed
{
	private:

	int	fixedValue;
	static const int fractBits;

	public:

	Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);

	Fixed(const int intie);
	Fixed(const float floatie);
	float	toFloat() const;
	int		toInt() const;
};

std::ostream &operator<<(std::ostream &outstream, const Fixed& member);

#endif