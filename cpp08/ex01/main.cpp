/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:40:26 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 06:03:23 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// int main()
// {
// 	Span span(10);
// 	int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// 	span.addNumbers(numbers, numbers + 10);
// 	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
// 	std::cout << "Longest span: " << span.longestSpan() << std::endl;
// 	return 0;
// }

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

// int main()
// {
// 	const int N = 10000;
// 	Span span(N);
// 	std::vector<int> numbers(N);
// 	std::srand(std::time(0));

// 	for (int i = 0; i < N; ++i)
// 		numbers[i] = std::rand();
// 	span.addNumbers(numbers.begin(), numbers.end());
// 	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
// 	std::cout << "Longest span: " << span.longestSpan() << std::endl;
// 	return 0;
// }