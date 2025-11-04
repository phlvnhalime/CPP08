/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:20:29 by hpehliva          #+#    #+#             */
/*   Updated: 2025/11/04 21:38:46 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5); // bottom of the stack
    mstack.push(17); // top of the stack
    std::cout << mstack.top() << std::endl; // show the top of stack
    mstack.pop(); // take the top of the stack
    std::cout << "\033[32m" << mstack.size() << "\033[0m" << std::endl; // only one element in the stack
    mstack.push(3); // bottom of the stack
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "==== Start a new iteration for counting ===== " << std::endl;
    size_t size = mstack.size();
    MutantStack<int>::const_iterator it_accessible = mstack.begin();
    for(size_t i = 0; i < size; i++)
    {
        std::cout << "Index: [" << i << "] = " << it_accessible[i] << std::endl;
    }

    return 0;
}