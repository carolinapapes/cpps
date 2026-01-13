/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:16:57 by capapes           #+#    #+#             */
/*   Updated: 2026/01/11 16:16:12 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _data;

public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);

    template <typename It>
    void addNumber(It begin, It end)
    {
        if (_data.size() + std::distance(begin, end) > _maxSize)
            throw std::runtime_error("Span is full");
        _data.insert(_data.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;
};



