/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:49:52 by mleibeng          #+#    #+#             */
/*   Updated: 2024/05/24 19:48:27 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>

class Contact
{
	private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkestsecret;

	public:
	Contact();
	Contact(const std::string& first, const std::string& last,
			const std::string& nick, const std::string& phone,
			const std::string& secret);

	std::string first() const;
	std::string last()	const;
	std::string nick()	const;
	std::string phone() const;
	std::string secret() const;
};

class PhoneBook
{
	private:
	Contact Booklet[8];
	int Contactamount;

	public:
	PhoneBook();

	void addContacts(const Contact& newContact);
	void searchContacts(const PhoneBook& contactlist);
	void exitProgram();
};

#endif