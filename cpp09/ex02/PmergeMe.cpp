/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:30:04 by mleibeng          #+#    #+#             */
/*   Updated: 2024/08/09 08:01:38 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::pair<std::vector<std::pair<int, int> >, int> pairVectorInput(std::vector<int>& vectorInput)
{
	std::vector<std::pair<int, int> > pairedInput;
	int last = -1;
	for (size_t i = 0; i < vectorInput.size() - 1; i += 2)
	{
		if (vectorInput[i] < vectorInput[i + 1])
			std::swap(vectorInput[i], vectorInput[i + 1]);
		pairedInput.push_back(std::make_pair(vectorInput[i], vectorInput[i + 1]));
	}
	if (vectorInput.size() % 2 != 0)
		last = vectorInput.back();
	return std::make_pair(pairedInput, last);
}

std::pair<std::deque<std::pair<int, int> >, int> pairDequeInput(std::deque<int>& dequeInput)
{
	std::deque<std::pair<int, int> > pairedInput;
	int last = -1;
	for (size_t i = 0; i < dequeInput.size() - 1; i += 2)
	{
		if (dequeInput[i] < dequeInput[i + 1])
			std::swap(dequeInput[i], dequeInput[i + 1]);
		pairedInput.push_back(std::make_pair(dequeInput[i], dequeInput[i + 1]));
	}
	if (dequeInput.size() % 2 != 0)
		last = dequeInput.back();
	return std::make_pair(pairedInput, last);
}

std::vector<int> mergeInsertionSortVector(std::vector<int>& input)
{
	if (input.size() <= 1)
		return input;
	std::pair<std::vector<std::pair<int, int> >, int> pairedInput = pairVectorInput(input);
	std::vector<std::pair<int, int> > pairedInputResult = pairedInput.first;
	int last = pairedInput.second;
	std::vector<int> larger;
	for (std::vector<std::pair<int, int> >::iterator iter = pairedInputResult.begin(); iter != pairedInputResult.end(); ++iter)
		larger.push_back(iter->first);
	std::vector<int> sorted = mergeInsertionSortVector(larger);
	std::vector<int> result = sorted;
	for (std::vector<std::pair<int, int> >::iterator iter = pairedInputResult.begin(); iter != pairedInputResult.end(); ++iter)
	{
		int position = binarySearch(result, iter->second);
		result.insert(result.begin() + position, iter->second);
	}
	if (last != -1)
	{
		int position = binarySearch(result, last);
		result.insert(result.begin() + position, last);
	}
	return result;
}


std::deque<int> mergeInsertionSortDeque(std::deque<int>& input)
{
	if (input.size() <= 1)
		return input;
	std::pair<std::deque<std::pair<int, int> >, int> pairedInput = pairDequeInput(input);
	std::deque<std::pair<int, int> > pairedInputResult = pairedInput.first;
	int last = pairedInput.second;

	std::deque<int> larger;
	for (std::deque<std::pair<int, int> >::iterator iter = pairedInputResult.begin(); iter != pairedInputResult.end(); ++iter)
		larger.push_back(iter->first);
	std::deque<int> sorted = mergeInsertionSortDeque(larger);
	std::deque<int> result = sorted;
	for (std::deque<std::pair<int, int> >::iterator iter = pairedInputResult.begin(); iter != pairedInputResult.end(); ++iter)
	{
		int position = binarySearch(result, iter->second);
		result.insert(result.begin() + position, iter->second);
	}
	if (last != -1)
	{
		int position = binarySearch(result, last);
		result.insert(result.begin() + position, last);
	}
	return result;
}
