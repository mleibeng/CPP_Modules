/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:16:26 by mleibeng          #+#    #+#             */
/*   Updated: 2024/08/10 21:48:51 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "won't be used anyway", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::beSigned(Bureaucrat& bureaucrat)
{
	AForm::beSigned(bureaucrat);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw GradeTooLowException();
	else if (executor.getGrade() > getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}