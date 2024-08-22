/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:51:54 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/04 01:25:05 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	inven_items = 0;
	for (int i = 0; i < 4; ++i)
		learned[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (learned[i] != NULL)
		{
			delete learned[i];
			learned[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy) : inven_items(copy.inven_items)
{
	for (int i = 0; i < 4; ++i)
	{
		if (copy.learned[i])
			learned[i] = copy.learned[i];
		else
			learned[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete learned[i];
			if (copy.learned[i])
				learned[i] = copy.learned[i];
			else
				learned[i] = NULL;
		}
		inven_items = copy.inven_items;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (inven_items < 4 && m)
		learned[inven_items++] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (learned[i] && learned[i]->getType() == type)
			return (learned[i]->clone());
	}
	return (NULL);
}