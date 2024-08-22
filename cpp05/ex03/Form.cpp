/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:12:24 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/10 22:37:12 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("blabla"), gradetosign(0), gradetoexec(0) {}

Form::Form(const std::string name, std::string target, const int gradetosign, const int gradetoexec) : name(name), signedconf(false), target(target), gradetosign(gradetosign), gradetoexec(gradetoexec)
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

std::string Form::getTarget() const
{
	return this->target;
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

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Grade too low";
}

void Form::beSigned(Bureaucrat &Bureaucrat)
{
	if (this->getSignGrade() >= Bureaucrat.getGrade())
		this->signedconf = true;
	else
		throw Form::GradeTooLowException();
}

void Form::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw GradeTooLowException();
	else if (executor.getGrade() > getExecGrade())
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &outstream, const Form &member)
{
	outstream << member.getName() << ", Sign grade " << member.getSignGrade() << " , Execution grade required " << member.getExecGrade() << " , Sign status = " << member.getSigned() << ".";
	return outstream;
}