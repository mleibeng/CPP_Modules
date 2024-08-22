/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:15:53 by mleibeng          #+#    #+#             */
/*   Updated: 2024/08/10 21:51:18 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "won't be used anyway", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beSigned(Bureaucrat& bureaucrat)
{
	AForm::beSigned(bureaucrat);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw GradeTooLowException();
	else if (executor.getGrade() > getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << "* drilling noises *" << std::endl;

	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}