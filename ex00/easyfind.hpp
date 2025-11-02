#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int nbr_to_find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), nbr_to_find);

    if(it != container.end())
    {
        std::cout << nbr_to_find << ":" << it - container.begin() << std::endl;
    }
    else {
        throw std::out_of_range("Number not found");
    }
    return it;
}

#endif