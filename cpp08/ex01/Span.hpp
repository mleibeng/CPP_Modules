/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:40:46 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 17:35:34 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <ctime>

class Span
{
	private:
	std::vector<int> data;
	size_t size;

	public:

	Span();
	Span(int num);
	Span(unsigned int num);
	Span(const Span &copy);
	Span &operator=(const Span &copy);
	~Span();

	void addNumber(int num);
	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

#endif