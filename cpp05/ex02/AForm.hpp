/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:12:10 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/04/17 12:47:35 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
	const std::string name;
	bool signedconf;
	const std::string target;
	const int gradetosign;
	const int gradetoexec;
	AForm();
	public:
	AForm(const std::string, std::string target, const int, const int);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	virtual ~AForm();

	std::string getName() const;
	std::string getTarget() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	virtual void beSigned(Bureaucrat &Bureaucrat); //change signed boolean mode to signed true if the bureaucrat grade is high enough
	virtual void execute(Bureaucrat const &executor) const = 0;
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

std::ostream &operator<<(std::ostream &outstream, const AForm &member);

#endif