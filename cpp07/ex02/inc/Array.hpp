/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:58:23 by capapes           #+#    #+#             */
/*   Updated: 2026/01/09 16:06:26 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>   // size_t
#include <exception> // std::exception

template <typename T>
class Array {
public:
	Array() : _data(0), _size(0) {}

	Array(unsigned int n) : _data(0), _size(n)
	{
		if (_size == 0) {
			_data = 0;
			return;
		}
		_data = new T[_size]; // default-initialized
	}

	Array(Array const &other) : _data(0), _size(0)
	{
		*this = other;
	}

	~Array()
	{
		delete[] _data;
	}

	Array &operator=(Array const &other)
	{
		if (this == &other)
			return *this;

		delete[] _data;
		_data = 0;
		_size = other._size;

		if (_size == 0)
			return *this;

		_data = new T[_size];
		for (size_t i = 0; i < _size; ++i)
			_data[i] = other._data[i];
		return *this;
	}

	class OutOfBoundsException : public std::exception {
	public:
		virtual const char *what() const throw() { return "Array index out of bounds"; }
	};

	T &operator[](size_t idx)
	{
		if (idx >= _size)
			throw OutOfBoundsException();
		return _data[idx];
	}

	T const &operator[](size_t idx) const
	{
		if (idx >= _size)
			throw OutOfBoundsException();
		return _data[idx];
	}

	size_t size() const { return _size; }

private:
	T      *_data;
	size_t  _size;
};



