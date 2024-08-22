/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:58 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/10 22:11:18 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("blabla") {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
		this->grade = copy.grade;
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Grade too high <1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Grade too low >150";
}

void Bureaucrat::incrementGrade(void)
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade -= 1;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade += 1;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

std::ostream &operator<<(std::ostream &outstream, const Bureaucrat &member)
{
	outstream << member.getName() << ", bureaucrat grade " << member.getGrade() << ".";
	return outstream;
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getSigned() == true)
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because Bureaucrat Grade too low." << std::endl;
}

Bureaucrat::~Bureaucrat() {}