/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:44:04 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/03 23:36:17 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Animal Thisshouldntwork;

	Animal *Bob = new Dog();
	Animal *John = new Cat();

	Bob->makeSound();
	John->makeSound();

	delete Bob;
	delete John;
	return 0;
}
