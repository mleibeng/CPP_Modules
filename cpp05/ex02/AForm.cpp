/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:12:24 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/10 22:11:35 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("blabla"), gradetosign(0), gradetoexec(0) {}

AForm::AForm(const std::string name, std::string target, const int gradetosign, const int gradetoexec) : name(name), signedconf(false), target(target), gradetosign(gradetosign), gradetoexec(gradetoexec)
{
	if (gradetosign < 1 || gradetoexec < 1)
		throw AForm::GradeTooHighException();
	else if (gradetosign > 150 || gradetoexec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : name(copy.name), signedconf(copy.signedconf), gradetosign(copy.gradetosign), gradetoexec(copy.gradetoexec) {}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
		this->signedconf = copy.signedconf;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return this->name;
}

std::string AForm::getTarget() const
{
	return this->target;
}

int AForm::getSignGrade() const
{
	return this->gradetosign;
}

int AForm::getExecGrade() const
{
	return this->gradetoexec;
}

bool AForm::getSigned() const
{
	return this->signedconf;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm Grade too low";
}

void AForm::beSigned(Bureaucrat &Bureaucrat)
{
	if (this->getSignGrade() >= Bureaucrat.getGrade())
		this->signedconf = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &outstream, const AForm &member)
{
	outstream << member.getName() << ", Sign grade " << member.getSignGrade() << " , Execution grade required " << member.getExecGrade() << " , Sign status = " << member.getSigned() << ".";
	return outstream;
}