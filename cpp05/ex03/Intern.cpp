/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 07:46:33 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/10 21:06:12 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{
	formNames[0] = "shrubbery creation";
	formCreators[0] = &Intern::createShrubberyCreationForm;
	formNames[1] = "robotomy request";
	formCreators[1] = &Intern::createRobotomyRequestForm;
	formNames[2] = "presidential pardon";
	formCreators[2] = &Intern::createPresidentialPardonForm;
}

Intern::Intern(const Intern& copy)
{
	for (int i = 0; i < 3; ++i)
	{
		formNames[i] = copy.formNames[i];
		formCreators[i] = copy.formCreators[i];
	}
}

Intern &Intern::operator=(const Intern &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 3; ++i)
		{
			formNames[i] = copy.formNames[i];
			formCreators[i] = copy.formCreators[i];
		}
	}
	return *this;
}

Intern::~Intern() {}

Form* Intern::makeForm(const std::string& formName, const std::string& target)
{
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	std::cout << "Form name not recognized: " << formName << std::endl;
	return NULL;
}

Form* Intern::createShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

Form* Intern::createRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

Form* Intern::createPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}