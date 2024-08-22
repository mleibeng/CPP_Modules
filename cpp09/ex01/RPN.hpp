/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:29:39 by mleibeng          #+#    #+#             */
/*   Updated: 2024/08/09 01:46:40 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <cctype>

std::list<std::string> saveString(const std::string& rpnNotation);
int calcRPN(const std::list<std::string>& tokens);

#endif