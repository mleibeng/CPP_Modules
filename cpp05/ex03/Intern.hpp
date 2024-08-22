/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 07:46:41 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/10 22:12:00 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	typedef Form* (Intern::*FormCreator)(const std::string& target);
	Form* createShrubberyCreationForm(const std::string& target);
	Form* createRobotomyRequestForm(const std::string& target);
	Form* createPresidentialPardonForm(const std::string& target);

	std::string formNames[3];
	FormCreator formCreators[3];

public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	Form* makeForm(const std::string& formName, const std::string& target);

};