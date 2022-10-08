//
// Created by yuumo on 2022/08/11.
//

#ifndef EX00_EASYFIND_HPP
#define EX00_EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &intContainer, const int target) {
	typename T::iterator iter;

	iter = std::find(intContainer.begin(), intContainer.end(), target);
	return iter;
}

template<typename T>
typename T::const_iterator easyfind(const T &intContainer, const int target) {
  typename T::const_iterator iter;

  iter = std::find(intContainer.begin(), intContainer.end(), target);
  return iter;
}

#endif //EX00_EASYFIND_HPP
