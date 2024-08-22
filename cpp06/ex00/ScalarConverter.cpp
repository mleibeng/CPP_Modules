/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:59:37 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 03:28:50 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

bool custom_isnan(long double value)
{
	return value != value;
}

bool custom_isinf(long double value)
{
	return value == std::numeric_limits<double>::infinity() ||
			value == -std::numeric_limits<double>::infinity();
}

bool fixinput(const std::string& convertable)
{
	if (convertable.size() > 1 && convertable[convertable.size() - 1] == 'f' && (convertable != "inf" && convertable != "-inf"))
		return true;
	return false;
}

void ScalarConverter::convert(const std::string& convertable)
{
	std::string in = convertable;
	if(fixinput(convertable))
		in = in.substr(0, in.size() - 1);
	std::stringstream ss(in);
	char	cconvert;
	float	fconvert;
	int		iconvert;
	double	dconvert;

	ss >> dconvert;

	if (custom_isinf(dconvert))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << (dconvert > 0 ? "inff" : "-inff") << std::endl;
		std::cout << "double: " << (dconvert > 0 ? "inf" : "-inf") << std::endl;
		return;
	}

	if (custom_isnan(dconvert) || (ss.fail() || !ss.eof()))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}

	if (dconvert >= std::numeric_limits<char>::min() && dconvert <= std::numeric_limits<char>::max())
	{
		cconvert = static_cast<char>(dconvert);
		if (std::isprint(cconvert))
			std::cout << "char: '" << cconvert << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	if (dconvert >= static_cast<double>(std::numeric_limits<int>::min()) &&
		dconvert <= static_cast<double>(std::numeric_limits<int>::max()))
	{
		iconvert = static_cast<int>(dconvert);
		std::cout << "int: " << iconvert << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;

	if (dconvert >= -std::numeric_limits<float>::max() && dconvert <= std::numeric_limits<float>::max())
	{
		fconvert = static_cast<float>(dconvert);
		std::cout << "float: " << std::fixed << std::setprecision(1) << fconvert << "f" << std::endl;
	}
	else
		dconvert > 0 ? std::cout << "float: inff" << std::endl : std::cout << "float: -inff" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << dconvert << std::endl;
}
