/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:29:01 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/03 23:20:45 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain
{
	protected:
	std::string ideas[100];

	public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);
	virtual ~Brain();
	void setIdea(int index, const std::string &idea);
	std::string getIdea(int index) const;
};

#endif