/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:40:11 by hpehliva          #+#    #+#             */
/*   Updated: 2025/11/02 16:50:24 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cmath>

class Span {
    private:
        unsigned int N;
        // for storing integers
        std::vector<int> vec;
    public:
        // Constructor there is only parameter
        Span(unsigned int N);
        // Copy constructor
        Span(const Span& other);
        // Destructor
        ~Span(void);
        // Copy assignment operator
        Span& operator=(const Span& other);


        // Add a number to the vector
        void addNumber(int number);

        template <typename Iter>
        void addNumberRange(Iter begin, Iter end);
        long shortestSpan(void) const;
        long longestSpan(void) const;

        class SpanFullException: public std::out_of_range {
            public:
                SpanFullException() : std::out_of_range("Error: Span is already full") {}
        };

        class NoSpanException: public std::logic_error{
            public:
                NoSpanException() : std::logic_error("Error: No span found (0 or 1 number stored)") {}
        };
};

// Add the template implementation here

template <typename Iter>
void Span::addNumberRange(Iter begin, Iter end)
{
    if(std::distance(begin, end) > N - vec.size())
    {
        throw SpanFullException();
    }
    vec.insert(vec.end(), begin, end); // position , first and last for iterators
}


#endif