/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:59:46 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 02:05:22 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>
#include <cmath>

class ScalarConverter
{
	private:
	ScalarConverter();
	public:

	static void convert(const std::string &convertable);
};

#endif