/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:13:42 by hpehliva          #+#    #+#             */
/*   Updated: 2025/11/04 21:15:55 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack> // pop, push, top
#include <iostream>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> // interited from std::stack
{
public:
    using iterator = typename std::stack<T>::container_type::iterator;
    using const_iterator = typename std::stack<T>::container_type::const_iterator;

    iterator begin(void) { return this->c.begin(); }
    iterator end(void) { return this->c.end(); }
    const_iterator begin(void) const { return this->c.begin(); }
    const_iterator end(void) const { return this->c.end(); }
};

#endif