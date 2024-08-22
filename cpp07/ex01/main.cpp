/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:56:19 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 04:41:12 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <typename T>
void printElement(const T& element)
{
	std::cout << element << " ";
}

template <typename T>
void printStringElement(const T* element)
{
	std::cout << element << " ";
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t length = sizeof(arr) / sizeof(arr[0]);
	char arr2[] = {'a', 'b', 'c', 'd', 'e'};
	size_t length2 = sizeof(arr2) / sizeof(arr2[0]);
	const char* arr3[] = {"hello", "world", "this", "is", "an", "array", "of", "char", "strings"};
	size_t length3 = sizeof(arr3) / sizeof(arr3[0]);
	std::string arr4[] = {"hello", "world", "this", "is", "a", "std::string", "array"};
	size_t length4 = sizeof(arr4) / sizeof(arr4[0]);

	std::cout << "Array elements (while loop): ";
	iter(arr, length, printElement<int>);
	std::cout << "Array elements (char while loop): ";
	iter(arr2, length2, printElement<char>);
	std::cout << "Array elements (char string while loop): ";
	iter(arr3, length3, printStringElement<const char>);
	std::cout << "Array elements (std::string while loop): ";
	iter(arr4, length4, printElement<std::string>);

	return 0;
}