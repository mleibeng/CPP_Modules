/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:24 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/10 21:51:53 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testForm(AForm& form, Bureaucrat& signer, Bureaucrat& executor)
{
	std::cout << "\n--- Testing " << form.getName() << " ---\n";
	std::cout << form << std::endl;

	try
	{
		signer.signForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << signer.getName() << " couldn't sign " << form.getName() << ": " << e.what() << std::endl;
	}

	try
	{
		executor.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << executor.getName() << " couldn't execute " << form.getName() << ": " << e.what() << std::endl;
	}
}

int main()
{
	Bureaucrat lowRank("Alicia", 150);
	Bureaucrat midRank("Hensel", 50);
	Bureaucrat highRank("Gretel", 1);

	ShrubberyCreationForm shrubForm("home");
	testForm(shrubForm, lowRank, midRank);
	testForm(shrubForm, midRank, midRank);

	RobotomyRequestForm robotForm("Bender");
	testForm(robotForm, midRank, midRank);
	testForm(robotForm, highRank, highRank);

	PresidentialPardonForm pardonForm("Thomas");
	testForm(pardonForm, midRank, highRank);
	testForm(pardonForm, highRank, highRank);

	return 0;
}