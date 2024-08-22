/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:12:10 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/10 22:03:04 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
	const std::string name;
	bool signedconf;
	const int gradetosign;
	const int gradetoexec;
	Form();
	public:
	Form(const std::string, const int, const int);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	virtual ~Form();

	std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(Bureaucrat &Bureaucrat); //change signed boolean mode to signed true if the bureaucrat grade is high enough
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &outstream, const Form &member);

#endif