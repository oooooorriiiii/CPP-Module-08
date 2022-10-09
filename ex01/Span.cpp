//
// Created by yuumo on 2022/08/11.
//

#include <algorithm>

#include "Span.hpp"

Span::Span(const unsigned int sizeMax)
    : elemVec_(std::vector<int>()), _sizeMax(sizeMax) {}

Span::Span(const Span &other) {
  *this = other;
}

Span &Span::operator=(const Span &rhs) {
  if (this == &rhs)
    return *this;
  elemVec_ = rhs.getElemVec();
  _sizeMax = rhs._sizeMax;
  return *this;
}

Span::~Span() {}


/*
 * Member functions
 */

void Span::addNumber(int n) {
  if (elemVec_.size() >= _sizeMax)
    throw std::out_of_range("Span is full");
  elemVec_.push_back(n);
}

unsigned int Span::shortestSpan() const {
  if (elemVec_.size() < 2)
    throw std::out_of_range("Too few elements");

  std::vector<int> sortedVec = elemVec_;
  std::sort(sortedVec.begin(), sortedVec.end());

  unsigned int shortestSpan = UINT_MAX;
  for (unsigned int i = 0; i < sortedVec.size() - 1; ++i) {
    unsigned int span = sortedVec[i + 1] - sortedVec[i];
    if (span < shortestSpan)
      shortestSpan = span;
  }
  return shortestSpan;
}

unsigned int Span::longestSpan() const {
  if (elemVec_.size() < 2)
    throw std::out_of_range("Too few elements");

  std::vector<int> sortedVec = elemVec_;
  std::sort(sortedVec.begin(), sortedVec.end());
  return sortedVec.at(sortedVec.size() - 1) - sortedVec.at(0);
}

void Span::setPrint() {
  std::cout << "setPrint+++" << std::endl;
  for (std::vector<int>::iterator i = elemVec_.begin(); i != elemVec_.end(); ++i)
    std::cout << *i << std::endl;
  std::cout << "++++++++" << std::endl;
}

const std::vector<int>& Span::getElemVec() const {
  return elemVec_;
}
