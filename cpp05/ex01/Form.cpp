/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:12:24 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/10 22:11:32 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("blabla"), gradetosign(0), gradetoexec(0) {}

Form::Form(const std::string name, const int gradetosign, const int gradetoexec) : name(name), signedconf(false), gradetosign(gradetosign), gradetoexec(gradetoexec)
{
	if (gradetosign < 1 || gradetoexec < 1)
		throw Form::GradeTooHighException();
	else if (gradetosign > 150 || gradetoexec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : name(copy.name), signedconf(copy.signedconf), gradetosign(copy.gradetosign), gradetoexec(copy.gradetoexec) {}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
		this->signedconf = copy.signedconf;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
	return this->name;
}

int Form::getSignGrade() const
{
	return this->gradetosign;
}

int Form::getExecGrade() const
{
	return this->gradetoexec;
}

bool Form::getSigned() const
{
	return this->signedconf;
}

void Form::beSigned(Bureaucrat &Bureaucrat)
{
	if (this->getSignGrade() >= Bureaucrat.getGrade())
		this->signedconf = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Grade too low";
}

std::ostream &operator<<(std::ostream &outstream, const Form &member)
{
	outstream << member.getName() << ", Sign grade " << member.getSignGrade() << " , Execution grade required " << member.getExecGrade() << " , Sign status = " << member.getSigned() << ".";
	return outstream;
}