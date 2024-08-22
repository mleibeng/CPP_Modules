/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:40:37 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 17:41:01 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : size(0) {}

Span::Span(int num) : size(num) {}

Span::Span(unsigned int num) : size(num) {}

Span::Span(const Span &copy) : data(copy.data), size(copy.size) {}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		data = copy.data;
		size = copy.size;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if(data.size() >= size)
		throw std::runtime_error("Span full");
	data.push_back(num);
}

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	if(std::distance(begin, end) + data.size() > size)
		throw std::runtime_error("Span full");
	data.insert(data.end(), begin, end);
}

unsigned int Span::shortestSpan() const
{
	if (data.size() < 2)
		throw std::runtime_error("not enough numbers for a span");
	std::vector<int>sorted(data);
	std::sort(sorted.begin(), sorted.end());
	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
		minSpan = std::min(minSpan, sorted[i] - sorted[i - 1]);
	return (minSpan);
}

//either sort or just use a search STL that return iterators (when not derefed)
unsigned int Span::longestSpan() const
{
	if (data.size() < 2)
		throw std::runtime_error("not enough numbers for a span");
	return (*std::max_element(data.begin(), data.end()) - *std::min_element(data.begin(), data.end()));
}

//linker instructions for template instantiation. linux compiler throws an error here if they do not exist.
template void Span::addNumbers<int*>(int*, int*);
template void Span::addNumbers<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);
template void Span::addNumbers<std::vector<int>::const_iterator>(std::vector<int>::const_iterator, std::vector<int>::const_iterator);