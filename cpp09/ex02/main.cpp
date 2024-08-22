/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:29:51 by mleibeng          #+#    #+#             */
/*   Updated: 2024/08/11 00:19:00 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copy-pasta explanation from stackexchange:
/*The Ford-Johnson merge-insertion sort is a three-step algorithm, let 𝑛

be the number of elements to sort: Split the collection in 𝑛/2 pairs of 2 elements and order these elements pairwise.
If the number of elements is odd, the last element of the collection isn't paired with any element.

Recursively sort the pairs of elements by their highest value.
If the number of elements is odd, the last element is not considered a highest value and is left at the end of the collection.
Consider that the highest values form a sorted list that we will call the main chain while the rest of the elements will be known as pend elements.
Tag the elements of the main chain with the names 𝑎1,𝑎2,𝑎3,...,𝑎𝑛/2 then tag the pend elements with the names 𝑏1,𝑏2,𝑏3,...,𝑏𝑛/2.
For every 𝑘, we have the relation 𝑏𝑘≤𝑎𝑘.

Insert the pend elements into the main chain. We know that the first pend element 𝑏1 is lesser than 𝑎1;
we consider it to be part of the main chain which then becomes {𝑏1,𝑎1,𝑎2,𝑎3,...,𝑎𝑛/2}.
Now, we need to insert the other pend elements into the main chain in a way that ensures that the size of the insertion area is a power of 2 minus 1 as often as possible.
Basically, we will insert 𝑏3 in {𝑏1,𝑎1,𝑎2} (we know that it is less than 𝑎3), then we will insert 𝑏2 into {𝑏1,𝑎1,𝑏3} no matter where 𝑏3 was inserted.
Note that during these insertions, the size of the insertion area is always at most 3.

The value of the next pend element 𝑏𝑘 to insert into the main chain while minimizing the number of comparisons actually corresponds to the next Jacobsthal number.
We inserted the element 3 first, so the next will be 5 then 11 then 21, etc...

To sum up, the insertion order of the first pend elements into the main chain is as follows: 𝑏1,𝑏3,𝑏2,𝑏5,𝑏4,𝑏11,𝑏10,𝑏9,𝑏8,𝑏7,𝑏6,...

[3, 1, 4, 1, 5, 9, 2, 6]
   ↓
[(3,1), (4,1), (5,9), (2,6)]

[(3,1), (4,1), (9,5), (6,2)]
   ↓
Main chain:    3 → 4 → 9 → 6
Pend elements: 1   1   5   2

Insertion order: b1, b3, b2, b5, b4, ...

Initial:     b1 → 3 → 4 → 9 → 6
After b3:    b1 → 3 → 4 → 5 → 9 → 6
After b2:    1 → b1 → 3 → 4 → 5 → 9 → 6
.*/

//would prefer to use a std::vector and as second option probably a list
// to compare a container utilizing contiguous memory compared to a container not having access to random access and displaying the necessity of it for the Ford-Johnson
// -> Addition changed ex01 to utilize list instead, since implementing it here would make it impossible to use the Ford-Johnson on the second container.
// -> Will go ahead using deque as comparison container.

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Not enough arguments to execute" << std::endl;
		return 1;
	}

	std::vector<int> vectorInput;
	std::deque<int> dequeInput;
	std::vector<int> sortcompare;
	if (parse(argc,argv,vectorInput))
		return 1;
	if (parse(argc,argv,dequeInput))
		return 1;
	if (parse(argc, argv, sortcompare))
		return 1;
	std::cout << "Before:   ";
	for (std::vector<int>::iterator iter = vectorInput.begin(); iter != vectorInput.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;

	clock_t startVecTime = clock();
	std::vector<int> sortedVecOutput = mergeInsertionSortVector(vectorInput);
	clock_t endVecTime = clock();
	double durationVecTime = static_cast<double>(endVecTime - startVecTime) / CLOCKS_PER_SEC * 1000000;

	clock_t startDeqTime = clock();
	std::deque<int> sortedDeqOutput = mergeInsertionSortDeque(dequeInput);
	clock_t endDeqTime = clock();
	double durationDeqTime = static_cast<double>(endDeqTime - startDeqTime) / CLOCKS_PER_SEC * 1000000;

	clock_t startSortTime = clock();
	std::sort(sortcompare.begin(), sortcompare.end());
	clock_t endSortTime = clock();
	double durationSortTime = static_cast<double>(endSortTime - startSortTime) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After:	";
	for (std::vector<int>::iterator iter = sortedVecOutput.begin(); iter != sortedVecOutput.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of  " << argc - 1 << " elements with std::vector :   " << durationVecTime << " us" << std::endl;
	std::cout << "Time to process a range of  " << argc - 1 << " elements with std::deque  :   " << durationDeqTime << " us" << std::endl;
	std::cout << "Time to process a range of  " << argc - 1 << " elements with the std::sort function also know as IntroSort algorithm :   " << durationSortTime << " us" << std::endl;
	return 0;
}