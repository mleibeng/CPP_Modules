/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:14:42 by mleibeng          #+#    #+#             */
/*   Updated: 2024/08/10 21:50:37 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "won't be used anyway", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beSigned(Bureaucrat& bureaucrat)
{
	AForm::beSigned(bureaucrat);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw GradeTooLowException();
	else if (executor.getGrade() > getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	std::ofstream file((getTarget() + "_shrubbery").c_str());
	file << "    _\n"
		<< "   | |\n"
		<< "   | |_ _ __ ___   ___\n"
		<< "   | __| '__/ _ \\/ _ \\\n"
		<< "   | |_| | |  __/  __/\n"
		<< "   \\___|_| \\___|\\___|\n";
}