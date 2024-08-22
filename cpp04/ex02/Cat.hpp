/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:50:31 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/13 01:33:37 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
	Brain *brain;

	protected:
	std::string type;

	public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &copy);
	~Cat();

	void makeSound() const;
	std::string getType() const;
	void setBrainIdea(int index, const std::string &idea);
	std::string getBrainIdea(int index) const;
};

#endif