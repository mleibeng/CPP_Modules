/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:59:42 by mleibeng          #+#    #+#             */
/*   Updated: 2024/07/04 00:04:35 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	public:
	Cure();
	Cure(const Cure& copy);
	Cure &operator=(const Cure &copy);
	virtual ~Cure();

	std::string const &getType() const;
	Cure *clone() const;
	void use(ICharacter &target);
};

#endif