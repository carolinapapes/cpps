/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:55:17 by capapes           #+#    #+#             */
/*   Updated: 2026/01/09 16:00:06 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef> 

template <typename T>
void iter(T *arr, size_t len, void (*f)(T &))
{
	if (!arr || !f)
		return;
	for (size_t i = 0; i < len; ++i)
		f(arr[i]);
}

template <typename T>
void iter(T const *arr, size_t len, void (*f)(T const &))
{
	if (!arr || !f)
		return;
	for (size_t i = 0; i < len; ++i)
		f(arr[i]);
}

