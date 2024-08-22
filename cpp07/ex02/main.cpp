/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:25:12 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/12 23:28:29 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// int main()
// {
// 	Array<int> arr0;
// 	std::cout << &arr0 << std::endl;
// 	int i = 0;
// 	Array<int> arr1(5);
// 	while (i < arr1.size())
// 	{
// 		arr1[i] = i * 2;
// 		i++;
// 	}
// 	i = 0;
// 	std::cout << "Elements of arr1: ";
// 	for (int i = 0; i < arr1.size(); i++)
// 		std::cout << arr1[i] << " ";
// 	std::cout << std::endl;

// 	Array<int>* arr2 = new Array<int>(3);
// 	(*arr2)[0] = 10;
// 	(*arr2)[1] = 20;
// 	(*arr2)[2] = 30;

// 	std::cout << "Elements of arr2: ";
// 	for (int i = 0; i < arr2->size(); i++)
// 		std::cout << (*arr2)[i] << " ";
// 	std::cout << std::endl;

// 	delete arr2;

// 	try
// 	{
// 		arr1[10] = 0;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << "Error: out of bounds!!" << std::endl;
// 	}

// 	return 0;
// }

#include <cmath>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
	}