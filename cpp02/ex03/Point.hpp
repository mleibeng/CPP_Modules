/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:50:46 by mleibeng          #+#    #+#             */
/*   Updated: 2024/06/04 23:40:31 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
	private:
	Fixed const x;
	Fixed const y;

	public:
	Point();
	Point(const float a, const float b);
	Point(const Point &copy);
	Point &operator=(const Point&);
	const Fixed &geta() const;
	const Fixed &getb() const;
	~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif