/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:38 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/10 21:59:03 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat
{
	private:
	const std::string name;
	int grade;
	Bureaucrat();
	public:

	Bureaucrat(std::string const, int);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	virtual ~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void incrementGrade(void); //increment should decrement lol because 1 is the highest grade
	void decrementGrade(void); //same but opposite lol
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

std::ostream &operator<<(std::ostream &outstream, const Bureaucrat &member);

#endif