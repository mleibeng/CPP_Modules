/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:44:04 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/04 01:55:22 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->unequip(1);
	delete bob;
	delete me;
	delete src;
	return 0;
}


// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		AMateria* tmp = src->createMateria("ice");
// 		me->equip(tmp);
// 	}

// 	AMateria* unknown = src->createMateria("unknown");
// 	if (unknown == NULL)
// 		std::cout << "Unknown Materia type not created" << std::endl;


// 	MateriaSource* src2 = new MateriaSource();
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		if (i < 4)
// 		{
// 			src2->learnMateria(new Cure());
// 			std::cout << "Materia nr.: " << i + 1 << " learned " << std::endl;
// 		}
// 		else
// 			std::cout << "Maximum limit of learned Materias reached." << std::endl;
// 	}
// 	delete src;
// 	delete me;
// 	delete src2;
// 	return 0;
// }