/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 07:10:38 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 02:06:31 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <sstream>

class Serializer
{
	private:
	Serializer();
	public:

	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif