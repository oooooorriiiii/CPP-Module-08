//
// Created by yuumo on 2022/08/11.
//

#ifndef EX01_SPAN_HPP
#define EX01_SPAN_HPP

#include <climits>

#include <iostream>
#include <vector>
#include <set>

class Span {
 public:
  Span();
  Span(const unsigned int n);
  Span(const Span &span);
  Span &operator=(const Span &span);
  ~Span();

  void addNumber(int n);
  void addNumber(std::set<int>::const_iterator beginSet,
                 std::set<int>::const_iterator endSet);
  void addNumber(std::vector<int>::const_iterator beginVec,
                 std::vector<int>::const_iterator endVec);
  unsigned int shortestSpan() const throw(std::exception);
  unsigned int longestSpan() const throw(std::exception);

  void setPrint();

 private:
  std::set<int> _spanSet;
  unsigned int _sizeMax;
  unsigned int _shortestSpan;
};

#endif //EX01_SPAN_HPP
