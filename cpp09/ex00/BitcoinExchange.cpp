/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:03:26 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/06 20:55:36 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Custom error message for individual value errors
bool errorValue(const std::string& message)
{
	std::cerr << message << std::endl;
	return false;
}

bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

//YYYY-MM-DD Format, check for date limits, check for valid date && leapyear
bool validateDateFormat(const std::string& date)
{
	int year, month, day;
	int daysPerMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	std::stringstream ss(date);
	char connect;

	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	ss >> year >> connect >> month >> connect >> day;
	if (ss.fail() || !ss.eof())
		return false;

	if (month < 1 || month > 12 || day < 1)
		return false;

	if (isLeapYear(year))
		daysPerMonth[1] = 29;
	if (day > daysPerMonth[month - 1])
		return false;

	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	if (year < now->tm_year + 1900)
		return true;
	else if (year == now->tm_year + 1900)
	{
		if (month < now->tm_mon + 1)
			return true;
		else if (month == now->tm_mon + 1)
			return day < now->tm_mday;
	}
	return false;
}

//Values must be between 0 and 1000 and must not contain any characters
bool validateValueFormat(const std::string& value, float& floatVal)
{
	char* endPtr;
	float val = std::strtof(value.c_str(), &endPtr);
	if (*endPtr == '\0')
	{
		if (val >= 0.0f && val <= 1000.0f)
		{
			floatVal = val;
			return true;
		}
		else if (val > 1000.0f)
			return errorValue("Error: too large a number.");
		else
			return errorValue("Error: not a positive number.");
	}
	else
		return errorValue("Error: invalid characters in the string.");
}