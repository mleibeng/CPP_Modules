/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 07:51:46 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 03:41:00 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	std::srand(std::time(0));

	Base* obj = generate();

	std::cout << "Identifying objects using pointers:" << std::endl;
	identify(obj);

	std::cout << "\nIdentifying objects using references:" << std::endl;
	identify(*obj);

	delete obj;

	return 0;
}
