/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:25:11 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/06/28 14:58:48 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	try
	{
		easyfind(v, 3);
		easyfind(v, 6);
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		easyfind(l, 3);
		easyfind(l, 6);
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
