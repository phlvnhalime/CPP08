/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:32:07 by hpehliva          #+#    #+#             */
/*   Updated: 2025/11/02 16:52:46 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N): N(N) {}

Span::Span(const Span& other): N(other.N), vec(other.vec) {}

Span& Span::operator=(const Span& other)
{
    if(this != &other)
    {
        N = other.N;
        vec = other.vec;
    }
    return *this;
}

Span::~Span(void)
{

}

void Span::addNumber(int number)
{
    if(vec.size() >= N)
    {
        throw SpanFullException();
    }
    vec.push_back(number);
}

long Span::shortestSpan(void) const
{
    if(vec.size() <= 1)
    {
        throw NoSpanException();
    }
    std::vector<int> shortest = vec;
    std::sort(shortest.begin(), shortest.end());
    // start 2 number in vector and compare them
    long minSpan = static_cast<long>(shortest[1]) - static_cast<long>(shortest[0]);

    for(size_t i = 2; i < shortest.size(); i++)
    {
        long currSpan = static_cast<long>(shortest[i]) - static_cast<long>(shortest[i - 1]);
        if(currSpan < minSpan)
        {
            minSpan = currSpan;
        }
    }
    std::cout << "Shortest span: " << minSpan << std::endl;
    return minSpan;
}

long Span::longestSpan(void) const
{
    if(vec.size() <= 1){
        throw NoSpanException();
    }
    // Using the STL algorithm to find min and max element in the vector
    std::vector<int>::const_iterator min = std::min_element(vec.begin(), vec.end()); // find the smallest number in the vector
    std::vector<int>::const_iterator max = std::max_element(vec.begin(), vec.end()); // find the largest number in the vector
    return static_cast<long>(*max) - static_cast<long>(*min); // return the difference between the largest and smallest number
}

