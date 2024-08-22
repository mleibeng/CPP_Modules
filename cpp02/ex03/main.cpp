/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:14:25 by mleibeng          #+#    #+#             */
/*   Updated: 2024/06/09 20:16:41 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int	main(void)
{
	Point a(0, 0.0f);
	Point b(10.0f, 30.0f);
	Point c(20.0f, 0.0f);
	Point point(30.0f, 15.0f);

	std::cout << (bsp(a, b, c, point) ? "yes" : "no") << std::endl;
	return 0;
}
