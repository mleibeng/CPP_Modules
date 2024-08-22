/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:24 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/10 21:22:51 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Hensel", 50);
		std::cout << b1 << std::endl;
		Form form1("Form 1", 40, 20);
		std::cout << form1 << std::endl;
		b1.signForm(form1);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b2("Gretel", 150);
		std::cout << b2 << std::endl;
		Form form2("Form 2", 10, 151);
		std::cout << form2 << std::endl;
		b2.signForm(form2);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b3("Alicia", 1);
		std::cout << b3 << std::endl;
		Form form3("Form 3", 5, 0);
		std::cout << form3 << std::endl;
		b3.signForm(form3);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b4("Hans", 100);
		std::cout << b4 << std::endl;
		Form form4("Form 4", 100, 100);
		std::cout << form4 << std::endl;
		form4.beSigned(b4);
		b4.signForm(form4);
		std::cout << form4 << std::endl;
		b4.decrementGrade();
		std::cout << b4 << std::endl;
		form4.beSigned(b4);
		b4.signForm(form4);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
