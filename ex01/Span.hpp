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
  Span(const unsigned int n = 0);
  Span(const Span &span);
  Span &operator=(const Span &rhs);
  ~Span();

  void addNumber(int n);
  template<class T>
  void addNumber(T begin, T end) {
    while (begin != end) {
      if (elemVec_.size() == _sizeMax)
        throw std::out_of_range("Span is full");
      elemVec_.push_back(*begin);
      begin++;
    }
  }
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;

  void setPrint();

  const std::vector<int>& getElemVec() const;

 private:
  std::vector<int> elemVec_;
  unsigned int _sizeMax;
};

#endif //EX01_SPAN_HPP
