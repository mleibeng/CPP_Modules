/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:03:08 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/06 21:12:30 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Start Idea:
//What to do: readout csv and input txt, save as std:string date key - float value pairs for both into maps
//	-> correction saving the account info into map was incorrect due to it overwriting information when the key was similar.
//	-> Now i iterate through each line of the input file and process it directly without saving.
//readout key string and convert into time format to compare to closest timeformat using algorithm (maybe sort and then smallest span downwards or something)
//convert back into keystring for lookup after finding the closest valid date. then do key value readout and multiply both values with each other, then print them to terminal.
//error handling: no negative values / invalid dates ex: 2001-42-42 / values over 1000

//addition: maybe I just ignore the conversion to timeformat and compare raw string values,
//so i need to add additional error checks to make sure the formatting is the same YYYY-MM-DD so a comparison is viable.
//probably more efficient than performing conversion to and back from time format, thus reducing performance overhead and simplifying the code.

static inline bool not_space(int c)
{
	return !std::isspace(c);
}

static inline void ltrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), not_space));
}

// Trim from end (in place)
static inline void rtrim(std::string &s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), not_space).base(), s.end());
}

// Trim from both ends (in place)
static inline void trim(std::string &s)
{
	ltrim(s);
	rtrim(s);
}

// Using lower_bound find the first occurence of a number not lower than target inside the bitcoinDatabase.
// set iter to that occurence, if it is the first occurence we do not need to decrease iter any further,
// otherwise decrease iter to the next lower value of the targetDate in case targetDate is non-existent inside of the map.
std::string findClosest(const std::map<std::string, float>& bitcoinDatabase, const std::string& targetDate)
{
	std::map<std::string, float>::const_iterator iter = bitcoinDatabase.lower_bound(targetDate);
	if (iter != bitcoinDatabase.begin())
	{
		if(iter == bitcoinDatabase.end() || iter->first != targetDate)
			--iter;
	}
	return iter->first;
}

// Function to save the csv data into an ordered map utilizing dates as keys.
int csvReadout(std::map<std::string, float>& bitcoinDatabase)
{
	std::ifstream bitcoinCSV("data.csv");
	if (bitcoinCSV.is_open())
	{
		std::string line;
		while (std::getline(bitcoinCSV, line))
		{
			std::stringstream ss(line);
			std::string date, value;
			std::getline(ss, date, ',');
			std::getline(ss, value);
			bitcoinDatabase[date] = std::strtof(value.c_str(), NULL);
		}
		bitcoinCSV.close();
		return 0;
	}
	else
	{
		std::cerr << "Unable to open bitcoin_database.csv" << std::endl;
		return 1;
	}
}

// Function to save and validate the input from the account data file into an ordered map utilizing dates as keys.
int inputReadout(std::map<std::string, float>& bitcoinDatabase, char *argv)
{
	std::ifstream inputFile(argv);
	if (inputFile.is_open())
	{
		std::string line;
		bool firstLine = true;
		while (std::getline(inputFile, line))
		{
			if (firstLine)
			{
				firstLine = false;
				continue;
			}
			std::stringstream ss(line);
			std::string date, value;
			std::getline(ss, date, '|');
			std::getline(ss, value);

			trim(date);
			trim(value);

			if (!validateDateFormat(date))
			{
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			float floatVal;
			if (!validateValueFormat(value, floatVal))
				continue;
			std::string targetDate = findClosest(bitcoinDatabase, date);
			float result = floatVal * bitcoinDatabase.at(targetDate);
			std::cout << date << " => " << floatVal << " = " << result << std::endl;
		}
		inputFile.close();
		return 0;
	}
	else
	{
		std::cerr << "Unable to open input file" << argv << std::endl;
		return 1;
	}
}

int main(int argc, char **argv)
{
	std::map<std::string, float> bitcoinDatabase;
	if (argc != 2)
	{
		std::cerr << "Usage: not enough arguments" << std::endl;
		return 1;
	}
	if (csvReadout(bitcoinDatabase))
		return 1;
	if (inputReadout(bitcoinDatabase, argv[1]))
		return 1;
	return 0;
}
