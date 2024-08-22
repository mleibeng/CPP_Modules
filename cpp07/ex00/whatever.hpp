/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:44:09 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/07/03 21:13:39 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename temple>

void swap(temple &a, temple &b)
{
	temple temp = a;
	a = b;
	b = temp;
}

template <typename temple>
temple max(const temple& a, const temple& b)
{
	if (a > b)
		return a;
	else
		return b;
}
template <typename temple>
temple min(const temple& a, const temple& b)
{
	if (a < b)
		return a;
	else
		return b;
}
#endif