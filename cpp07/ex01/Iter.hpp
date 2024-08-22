/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:56:27 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 04:41:38 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename IT, typename Func>
void iter(IT *address, size_t length, Func func)
{
	size_t i;

	i = 0;
	while (i < length)
	{
		func(address[i]);
		i++;
	}
	// std::cout << std::endl;
}

#endif