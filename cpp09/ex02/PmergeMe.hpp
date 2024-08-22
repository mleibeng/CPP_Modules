/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:30:14 by mleibeng          #+#    #+#             */
/*   Updated: 2024/08/09 07:36:48 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <ctime>
#include <iomanip>

template<typename Container>
int parse(int argc, char **argv, Container& vec)
{
	for (int i = 1; i < argc; ++i)
	{
		int num = std::atoi(argv[i]);
		if (num <= 0)
		{
			std::cout << "Error" << std::endl;
			return 1;
		}
		vec.push_back(num);
	}
	return (0);
};
template<typename Container>
int	binarySearch(const Container& access, int x)
{
	int start = 0;
	int end = access.size() - 1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (access[mid] == x)
			return mid;
		else if (access[mid] < x)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return start;
};
std::pair<std::vector<std::pair<int,int> >, int> pairVectorInput(std::vector<int>& vectorInput);
std::pair<std::deque<std::pair<int,int> >, int> pairDequeInput(std::deque<int>& dequeInput);
std::vector<int> mergeInsertionSortVector(std::vector<int>& input);
std::deque<int> mergeInsertionSortDeque(std::deque<int>& input);


#endif