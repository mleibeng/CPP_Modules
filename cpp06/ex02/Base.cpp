/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 07:51:37 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 03:59:32 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int random = std::rand() % 3 + 1;

	switch(random)
	{
		case 1:
		return (new A());
		case 2:
		return (new B());
		case 3:
		return (new C());
		default:
			return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Type C" << std::endl;
}

//so why am I not allowed to do it like this?
// void identify(Base &p)
// {
// 	identify(&p);
// }

// bad_cast is part of typeinfo so using generic exception instead, since its not allowed...
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
		return;
	}
	catch(const std::exception& e) {};
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type B" << std::endl;
		return;
	}
	catch(const std::exception& e) {};
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type C" << std::endl;
		return;
	}
	catch(const std::exception& e) {};
}
