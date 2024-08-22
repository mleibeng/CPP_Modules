/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:40:59 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 17:54:19 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while(it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}


// #include <iostream>
// #include <list>

// int main() {
//     std::list<int> myList;
//     myList.push_back(5);
//     myList.push_back(17);

//     std::cout << myList.back() << std::endl;

//     myList.pop_back();

//     std::cout << myList.size() << std::endl;

//     myList.push_back(3);
//     myList.push_back(5);
//     myList.push_back(737);
//     myList.push_back(0);

//     std::list<int>::iterator it = myList.begin();
//     std::list<int>::iterator ite = myList.end();

//     ++it;
//     --it;

//     while (it != ite) {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main(void)
// {
// 	std::vector<int> mvec;

// 	mvec.push_back(5);
// 	mvec.push_back(17);

// 	std::cout << mvec.back() << std::endl;

// 	mvec.pop_back();
// 	std::cout << mvec.size() << std::endl;

// 	mvec.push_back(3);
// 	mvec.push_back(5);
// 	mvec.push_back(737);
// 	mvec.push_back(0);

// 	std::vector<int>::iterator it = mvec.begin();
// 	std::vector<int>::iterator ite = mvec.end();

// 	++it;
// 	--it;

// 	while(it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::vector<int> s(mvec);
// 	return (0);
// }