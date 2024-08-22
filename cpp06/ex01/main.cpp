/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 07:21:16 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 02:07:24 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data info;

	info.name = "Thomas";
	info.age = 30;
	info.acc_balance = 10000.0;

	uintptr_t raw = Serializer::serialize(&info);
	std::cout << "raw value: " << raw << std::endl;
	Data *new_info = Serializer::deserialize(raw);
	std::cout << "Address of info: " << &info << std::endl;
	std::cout << "Address of new_info: " << new_info << std::endl;

	if (new_info->name == info.name && new_info->age == info.age && new_info->acc_balance == info.acc_balance)
		std::cout << "conversion successfull" << std::endl;
	else
		std::cout << "conversion unsuccessfull" << std::endl;

	return 0;
}