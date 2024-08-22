/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:46:21 by mleibeng          #+#    #+#             */
/*   Updated: 2024/05/24 19:41:45 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>
#include <sstream>

int	main(int argc, char **argv)
{
	std::stringstream ss;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			for (char *iter = argv[i]; *iter; ++iter)
				ss << (char)std::toupper(*iter);
		}
		std::cout << ss.str() << std::endl;
	}
	return (0);
}