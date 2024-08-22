/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:29:33 by mleibeng          #+#    #+#             */
/*   Updated: 2024/08/16 01:58:50 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::list<std::string> saveString(const std::string& rpNotation)
{
	std::list<std::string> tokens;
	std::istringstream iss(rpNotation);
	std::string singleToken;

	while (iss >> singleToken)
		tokens.push_back(singleToken);
	return tokens;
}

int calcRPN(const std::list<std::string>& tokens)
{
	std::stack<int> numbers;
	for (std::list<std::string>::const_iterator iter = tokens.begin(); iter != tokens.end(); ++iter)
	{
		const std::string& token = *iter;
		if (token == "+" || token == "-" || token == "/" || token == "*" )
		{
			if (numbers.size() < 2)
				throw std::runtime_error("Not enough numbers for calculation");
			int b = numbers.top(); numbers.pop();
			int a = numbers.top(); numbers.pop();
			int result;
			if (token == "+")
				result = a + b;
			else if (token == "-")
				result = a - b;
			else if (token == "/")
				result = a / b;
			else if (token == "*")
				result = a * b;
			numbers.push(result);
		}
		else
		{
			char *end;
			long long value = std::strtoll(token.c_str(), &end, 10);
			if (*end != '\0' || end == token.c_str())
				throw std::invalid_argument("Not a number: " + token);
			if (value > INT_MAX || value < INT_MIN)
				throw std::overflow_error("Integer overflow");
			numbers.push(static_cast<int>(value));
		}
	}
	if (numbers.size() > 1)
		throw std::invalid_argument("Wrong RPN");
	return numbers.top();
}