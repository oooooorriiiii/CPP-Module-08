//
// Created by yuumo on 2022/08/11.
//

#ifndef EX00_EASYFIND_HPP
#define EX00_EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &t, const int target) {
  typename T::iterator iter;

  iter = std::find(t.begin(), t.end(), target);
  if (iter == t.end())
    throw std::runtime_error("not found");
  return iter;
}

template<typename T>
typename T::const_iterator easyfind(const T &t, const int target) {
  typename T::const_iterator iter;

  iter = std::find(t.begin(), t.end(), target);
  if (iter == t.end())
    throw std::runtime_error("not found");
  return iter;
}

#endif //EX00_EASYFIND_HPP
