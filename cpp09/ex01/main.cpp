/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:29:26 by mleibeng          #+#    #+#             */
/*   Updated: 2024/08/09 01:46:31 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Definitely needs a std::stack probably also going to use a deque -> works fine.
// need to implement error handling with try catch block!

#include "RPN.hpp"

int main(int argc, char **argv)
{

	if (argc < 2)
	{
		std::cerr << "No RPN given as argument" << std::endl;
		return (1);
	}
	std::string rpNotation = argv[1];
	std::list<std::string> tokens = saveString(rpNotation);

	try
	{
		int result = calcRPN(tokens);
		std::cout << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}