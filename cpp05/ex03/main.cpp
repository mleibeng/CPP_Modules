/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:24 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/10 22:31:08 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testForm(Form *form, Bureaucrat *signer, Bureaucrat *executor)
{
	if(!signer || !form || !executor)
	{
		std::cout << "error non-valid parameter" << std::endl;
		return;
	}
	std::cout << "\n--- Testing " << form->getName() << " ---\n";
	std::cout << *form << std::endl;
	try
	{
		signer->signForm(*form);
	}
	catch (std::exception& e)
	{
		std::cout << signer->getName() << " couldn't sign " << form->getName() << ": " << e.what() << std::endl;
	}
	try
	{
		executor->executeForm(*form);
	}
	catch (std::exception& e)
	{
		std::cout << executor->getName() << " couldn't execute " << form->getName() << ": " << e.what() << std::endl;
	}
}

int main()
{
	Intern Bob;
	Form *rrf;
	Form *scf;
	Form *ppf;
	Form *erf;
	Bureaucrat lowRank("Alicia", 150);
	Bureaucrat midRank("Hensel", 50);
	Bureaucrat highRank("Gretel", 1);

	scf = Bob.makeForm("shrubbery creation", "home");
	testForm(scf, &lowRank, &midRank);
	testForm(scf, &midRank, &midRank);
	std::cout << std::endl;
	rrf = Bob.makeForm("robotomy request", "Bender");
	testForm(rrf, &midRank, &midRank);
	testForm(rrf, &highRank, &highRank);
	std::cout << std::endl;
	ppf = Bob.makeForm("presidential pardon", "Thomas");
	testForm(ppf, &midRank, &highRank);
	testForm(ppf, &highRank, &highRank);
	std::cout << std::endl;
	erf = Bob.makeForm("error form", "bob is an idiot");
	testForm(erf, &highRank, &highRank);

	delete rrf, delete scf, delete ppf;
	return 0;
}
