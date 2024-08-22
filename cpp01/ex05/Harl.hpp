/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:56:45 by mleibeng          #+#    #+#             */
/*   Updated: 2024/03/06 08:29:04 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>
#include <map>

class Harl
{
	private:
	void	debug();
	void	info();
	void	warning();
	void	error();

	public:
	Harl();
	void	complain(std::string level);
	~Harl();
};

#endif