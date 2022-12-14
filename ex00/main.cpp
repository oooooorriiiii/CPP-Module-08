//
// Created by yuumo on 2022/08/02.
//

#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

void  testHeader(std::string str) {
  std::cout << "TEST******************" << std::endl;
  std::cout << str << std::endl;
  std::cout << "**********************" << std::endl;
}

int main() {
  {
    testHeader("std::list<int>");

    std::list<int> list;
    for (int i = 0; i < 10; ++i)
      list.push_back(i);

    try {
      std::cout << "" << *easyfind(list, 2) << std::endl;
      std::cout << "" << *easyfind(list, 12) << std::endl;
    }
    catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    testHeader("std::vector<int>");

    std::vector<int> vec;

    vec.reserve(10);
    for (int i = 0; i < 10; i++)
      vec.push_back(i);

    try {
      std::cout << "" << *easyfind(vec, 2) << std::endl;
      std::cout << "" << *easyfind(vec, 12) << std::endl;
    }
    catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return 0;
}