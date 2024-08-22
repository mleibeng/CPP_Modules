/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:29:04 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/03 23:22:50 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructed Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Empty thought";
}

Brain::Brain(const Brain &copy)
{
	for (size_t i = 0; i < 100; ++i)
		this->ideas[i] = copy.ideas[i];
	std::cout << "Constructed Brain (Copy)" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this != &copy)
	{
		for (size_t i = 0; i < 100; ++i)
			ideas[i] = copy.ideas[i];
	}
	std::cout << "Brain Assignment Operator" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain " << " deconstructed" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
			return ideas[index];
		else
			return "";
}