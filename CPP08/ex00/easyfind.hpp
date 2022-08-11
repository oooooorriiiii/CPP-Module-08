//
// Created by yuumo on 2022/08/11.
//

#ifndef EX00_EASYFIND_HPP
#define EX00_EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &intContainer, int target) {
	typename T::iterator iter;

	iter = std::find(intContainer.begin(), intContainer.end(), target);
	if (iter == intContainer.end())
		throw std::out_of_range("not found");
	return iter;
}

#endif //EX00_EASYFIND_HPP
