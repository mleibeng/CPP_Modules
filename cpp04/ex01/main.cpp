/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:44:04 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/03 23:27:45 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal* animals[10];

	for (int i = 0; i < 5; ++i)
		animals[i] = new Dog();
	for (int i = 5; i < 10; ++i)
		animals[i] = new Cat();

	Animal *animal = new Dog();
	delete animal;

	Dog originalDog;
	originalDog.setBrainIdea(0, "Fetch");
	Dog copiedDog = originalDog;
	copiedDog.setBrainIdea(0, "Play");
	std::cout << "Original Dog Idea: " << originalDog.getBrainIdea(0) << std::endl;
	std::cout << "Copied Dog Idea: " << copiedDog.getBrainIdea(0) << std::endl;

	Cat originalCat;
	originalCat.setBrainIdea(0, "Purr");
	Cat copiedCat = originalCat;
	copiedCat.setBrainIdea(0, "Sleep");
	std::cout << "Original Cat Idea: " << originalCat.getBrainIdea(0) << std::endl;
	std::cout << "Copied Cat Idea: " << copiedCat.getBrainIdea(0) << std::endl;

	for (int i = 0; i < 10; ++i)
	delete animals[i];

	return 0;
}
