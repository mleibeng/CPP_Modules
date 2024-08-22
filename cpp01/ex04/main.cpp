/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 06:03:41 by mleibeng          #+#    #+#             */
/*   Updated: 2024/06/01 22:36:22 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	replace(const std::string &filename, std::string &s1, std::string &s2)
{
	if (s1.empty())
	{
		std::cout << "string 1 cannot be empty" << std::endl;
		return ;
	}
	std::string readout;
	std::ifstream input(filename.c_str());
	if (!input.is_open())
	{
		std::cout << "error opening readin" << std::endl;
		return ;
	}
	std::ofstream output((filename + ".replace").c_str());
	if (!output.is_open())
	{
		std::cout << "error opening writein" << std::endl;
		return ;
	}

	// while (std::getline(input, readout))
	// {
	// 	std::stringstream stringsstream(readout);
	// 	std::string word;
	// 	std::string outputstream;

	// 	while (stringsstream >> word)
	// 	{
	// 		if (word == s1)
	// 			outputstream += s2 + " ";
	// 		else
	// 			outputstream += word + " ";
	// 	}
	// 	if(!outputstream.empty())
	// 		outputstream.erase(outputstream.size() - 1);
	// 	output << outputstream << std::endl;
	// }

	while (std::getline(input, readout))
	{
		std::string word;
		std::string::size_type position = 0;

		while((position = readout.find(s1, position)) != std::string::npos)
		{
			word.append(readout, 0, position);
			word.append(s2);
			position += s1.length();
			readout = readout.substr(position);
			position = 0;
		}
		word.append(readout);
		output << word << std::endl;
	}

	input.close();
	output.close();
}

int	main(int argc,char **argv)
{
	if (argc != 4)
		return (1);

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	replace(filename, s1, s2);
	return (0);
}