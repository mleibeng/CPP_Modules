/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:14:42 by mleibeng          #+#    #+#             */
/*   Updated: 2024/08/10 22:32:08 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", "won't be used anyway", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	Form::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beSigned(Bureaucrat& bureaucrat)
{
	Form::beSigned(bureaucrat);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	Form::execute(executor);
	std::ofstream file((getTarget() + "_shrubbery").c_str());
	file << "    _\n"
		<< "   | |\n"
		<< "   | |_ _ __ ___   ___\n"
		<< "   | __| '__/ _ \\/ _ \\\n"
		<< "   | |_| | |  __/  __/\n"
		<< "   \\___|_| \\___|\\___|\n";
}