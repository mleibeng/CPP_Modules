/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:51:16 by mleibeng          #+#    #+#             */
/*   Updated: 2024/06/04 23:39:28 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0.0f), y(0.0f) {}

Point::Point(const float a, const float b) : x(a), y(b) {}

Point::Point(const Point &copy) : x(copy.geta()), y(copy.getb()) {}

Point &Point::operator=(const Point&)
{
	return *this;
}

const Fixed &Point::geta() const
{
	return x;
}

const Fixed &Point::getb() const
{
	return y;
}

Point::~Point() {}
