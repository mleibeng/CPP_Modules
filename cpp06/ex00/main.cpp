/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:04:53 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 03:30:12 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


/* Checks to-do
	42
	42.0f
	inf
	nan
	-inf
	-nan
	123.456
	1e308 (1 x 10^38) / Max double value is tested by limits and is something like 1.7976.... x 10^38
	1e309 (1 X 10^39) / Bigger than max double because 1 order of magnitude
	-1e308 / almost max negative
	-1e309 / smaller than max negative
	0
*/
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "One argument required" << std::endl;
		return (1);
	}
	std::string argument(argv[1]);
	ScalarConverter::convert(argument);
	return (0);
}


// int main()
// {
// 	ScalarConverter::convert(std::to_string(std::numeric_limits<float>::max()));
// 	ScalarConverter::convert(std::to_string(std::numeric_limits<float>::max() * 1.2));
// 	ScalarConverter::convert(std::to_string(-std::numeric_limits<float>::max()));
// 	ScalarConverter::convert(std::to_string(-std::numeric_limits<float>::max() * 1.2));

// 	ScalarConverter::convert(std::to_string(std::numeric_limits<double>::max()));
// 	ScalarConverter::convert(std::to_string(-std::numeric_limits<double>::max()));

// 	return 0;
// }