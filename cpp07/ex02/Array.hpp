/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:25:23 by marvinleibe       #+#    #+#             */
/*   Updated: 2024/08/05 04:58:20 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T* arr;
		int len;

	public:
		Array() : arr(NULL), len(0) {}

		Array(unsigned int n) : len(n)
		{
			arr = new T[n];
		}

		Array(const Array& copy) : len(copy.size())
		{
			arr = new T[len];
			for (int i = 0; i < len; i++)
				arr[i] = copy.arr[i];
		}

		Array& operator=(const Array& copy)
		{
			if (this != &copy)
			{
				delete[] arr;
				len = copy.size();
				arr = new T[len];
				for (int i = 0; i < len; i++)
					arr[i] = copy.arr[i];
			}
			return *this;
		}

		~Array()
		{
			delete[] arr;
		}

		int size() const
		{
			return len;
		}

		T& operator[](int idx)
		{
			if (idx < 0 || idx >= len)
				throw std::exception();
			return arr[idx];
	}
};

#endif