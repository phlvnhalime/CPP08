/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:31:07 by hpehliva          #+#    #+#             */
/*   Updated: 2025/10/31 17:23:35 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void test_easyfind(int number_to_find)
{

    std::cout << "Searching for --- " << std::endl;
    std::vector<int> vec; // volume of vector is 0

    vec.push_back(10); // Volume of vector is 1 // push_back add the number with sequentially 
    vec.push_back(20); // Volume of vector is 2
    vec.push_back(30); // Volume of vector is 3
    vec.push_back(40);
    vec.push_back(50);

    try {
        std::vector<int>::iterator index = easyfind(vec, number_to_find);
        std::cout << "Found at index: " << *index << std::endl;
    }
    catch (std::out_of_range& e)
    {
        std::cerr << "List: " << e.what() << std::endl;
    }    
}




int main(void)
{
    std::cout << "\033[32m"<< " ==== §Exceptable test§ ==== " << "\033[0m" << std::endl;
    // Exceptable numbers to find
    test_easyfind(30);

    std::cout << std::endl;

    std::cout << "\033[32m"<< " ==== §Unexceptable test§ ==== " << "\033[0m" << std::endl;

    test_easyfind(60);

    return (0);
}