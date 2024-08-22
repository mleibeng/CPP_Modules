/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:49:49 by mleibeng          #+#    #+#             */
/*   Updated: 2024/05/27 15:21:40 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact() {}
Contact::Contact(const std::string& first, const std::string& last,
				const std::string& nick, const std::string& phone,
				const std::string& secret) : firstname(first), lastname(last),
				nickname(nick), phonenumber(phone), darkestsecret(secret) {}

std::string Contact::first() const
{
	return firstname;
}

std::string Contact::last() const
{
	return lastname;
}

std::string Contact::nick() const
{
	return nickname;
}

std::string Contact::phone() const
{
	return phonenumber;
}

std::string Contact::secret() const
{
	return darkestsecret;
}

PhoneBook::PhoneBook() : Contactamount(0) {}

void PhoneBook::addContacts(const Contact& newContact)
{
	if (Contactamount < 8)
		Booklet[Contactamount++] = newContact;
	else
	{
		for (int i = 1; i < 8; ++i)
			Booklet[i - 1] = Booklet[i];
		Booklet[7] = newContact;
	}
}

std::string truncateString(const std::string& string)
{
	if (string.length() > 9)
		return string.substr(0, 9) + ".";
	else
		return (string);
}

void PhoneBook::searchContacts(const PhoneBook& contactlist)
{
	std::cout << std::right << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << "|" << std::endl;
	for (int i = 0; i < contactlist.Contactamount; ++i)
	{
		std::cout << std::right << std::setw(10) << i + 1 << "|"
				  << std::setw(10) << truncateString(contactlist.Booklet[i].first()) << "|"
				  << std::setw(10) << truncateString(contactlist.Booklet[i].last()) << "|"
				  << std::setw(10) << truncateString(contactlist.Booklet[i].nick()) << "|" << std::endl;
	}
	if (contactlist.Contactamount <= 0)
	{
		std::cout << "No contacts in list, returning..." << std::endl;
		return;
	}
	std::string inputcheck;
	std::cout << "Please send an index to lookup" << std::endl;
	while (1)
	{
		std::getline(std::cin, inputcheck);
		if (std::isdigit(inputcheck[0]) && inputcheck.size() == 1 && contactlist.Contactamount > 0)
		{
			int indexcheck = std::stoi(inputcheck);
			if (indexcheck >= 1 && contactlist.Contactamount >= indexcheck)
			{
				std::cout << "First name: " << contactlist.Booklet[indexcheck - 1].first() << std::endl;
				std::cout << "Last name: " << contactlist.Booklet[indexcheck - 1].last() << std::endl;
				std::cout << "Nickname: " << contactlist.Booklet[indexcheck - 1].nick() << std::endl;
				std::cout << "Phone Number: " << contactlist.Booklet[indexcheck - 1].phone() << std::endl;
				std::cout << "Darkest Secret: " << contactlist.Booklet[indexcheck - 1].secret() << std::endl;
				return ;
			}
			else
			{
				std::cout << "Please input a valid index" << std::endl;
				continue ;
			}
		}
		else
		{
			std::cout << "Please pick a valid index" << std::endl;
			continue ;
		}
	}
	return ;
}

void	PhoneBook::exitProgram()
{
	exit(EXIT_SUCCESS);
}

bool validinput(const std::string& input)
{
	for (int i = 0; i < input.length(); ++i)
	{
		char c = input[i];
		if (isalpha(c))
			continue;
		else
			return false;
		if (!input[i + 1])
			return true;
	}
	return true;
}

bool validnumber(const std::string& input)
{
	for (int i = 0; i < input.length(); ++i)
	{
		if (std::isdigit(input[i]) || (input[i] == '+' && i == 0))
			continue ;
		else
			return false;
	}
	return true;
}

int	main()
{
	std::string input;
	PhoneBook contactlist;

	while (1)
	{
		std::cout << "Please enter a valid action (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			std::string first, last, nick, phone, secret;
			std::cout << "Please input your first name: ";
			std::cin >> first;
			while(!validinput(first))
			{
				std::cout << "Please input a valid first name: ";
				std::cin >> first;
			}
			std::cout << "Please input your last name: ";
			std::cin >> last;
			while(!validinput(last))
			{
				std::cout << "Please input a valid last name: ";
				std::cin >> last;
			}
			std::cout << "Please input your nickname: ";
			std::cin >> nick;
			while(!validinput(nick))
			{
				std::cout << "Please input a valid nickname: ";
				std::cin >> nick;
			}
			std::cout << "Please input your phonenumber: ";
			std::cin >> phone;
			while(!validnumber(phone))
			{
				std::cout << "Please input a valid phone number: ";
				std::cin >> phone;
			}
			std::cout << "Please input your darkest secret: ";
			std::cin >> secret;
			while(!validinput(secret))
			{
				std::cout << "Please input a valid secret of darkness: ";
				std::cin >> secret;
			}

			Contact contactinput(first, last, nick, phone, secret);
			contactlist.addContacts(contactinput);
		}
		else if (input == "SEARCH")
		{
			contactlist.searchContacts(contactlist);
			continue;
		}
		else if (input == "EXIT")
			contactlist.exitProgram();
		else
			continue;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return (0);
}