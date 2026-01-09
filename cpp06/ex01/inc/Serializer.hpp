/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09                                    #+#    #+#       */
/*   Updated: 2026/01/09                                    ###   ########.fr */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>   // size_t
#include <stdint.h>  // uintptr_t

#include "Data.hpp"

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data*     deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(Serializer const &);
	Serializer &operator=(Serializer const &);
	~Serializer();
};
