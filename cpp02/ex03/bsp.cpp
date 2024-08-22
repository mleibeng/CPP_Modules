/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:23:46 by mleibeng          #+#    #+#             */
/*   Updated: 2024/06/09 20:15:10 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed product(const Point &a, const Point &b, const Point &c)
{
	return (b.geta() - a.geta()) * (c.getb() - a.getb()) - (c.geta() - a.geta()) * (b.getb() - a.getb());
}

bool is_inside(const Point &a, const Point &b, const Point &c, const Point &point)
{
	Fixed crossres = product(a, b, point);
	(void)c;
	if (crossres > 0)
		return (true);
	else
		return (false);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool edgeab;
	bool edgebc;
	bool edgeca;

	edgeab = is_inside(a, b, c, point);
	edgebc = is_inside(b, c, a, point);
	edgeca = is_inside(c, a, b, point);
	if ((edgeab == true && edgebc == true && edgeca == true) || \
		(edgeab == false && edgebc == false && edgeca == false))
		return (true);
	else
		return (false);
}
