//
// Created by yuumo on 2022/08/11.
//

#include "Span.hpp"

Span::Span() {}

Span::Span(const unsigned int sizeMax)
    : _spanSet(std::set<int>()), _sizeMax(sizeMax), _shortestSpan(UINT_MAX) {}

Span::Span(const Span &span) {
  *this = span;
}

Span &Span::operator=(const Span &span) {
  if (this == &span)
    return *this;
  _spanSet.clear();
  std::copy(span._spanSet.begin(),
            span._spanSet.end(),
            std::inserter(_spanSet, _spanSet.begin()));
  _sizeMax = span._sizeMax;
  _shortestSpan = span._shortestSpan;
  return *this;
}

Span::~Span() {}


/*
 * Member functions
 */

/**
 * It will be used in order to fill a single number.
 * Any attempt to add a new element if there are already N elements stored should throw an exception.
 * @param n
 */
void Span::addNumber(int n) {
  if (_spanSet.size() >= _sizeMax)
    throw std::out_of_range("Span is full");

  if (!_spanSet.insert(n).second)
    return;

  std::set<int>::iterator setUpperNeighborIter = _spanSet.upper_bound(n);
  std::set<int>::iterator setLowerNeighborIter = --_spanSet.lower_bound(n);
  std::set<int>::iterator setEndIter = _spanSet.end();


  // Initialize exception
  if (_spanSet.size() == 1)
    return;

  unsigned int span;
  if (*setLowerNeighborIter == *setEndIter)
    // smallest
    span = *setUpperNeighborIter - n;
  else if (*setUpperNeighborIter == *setEndIter)
    // largest
    span = n - *setLowerNeighborIter;
  else {
    unsigned int LowerSpan = n - *setLowerNeighborIter;
    unsigned int UpperSpan = *setUpperNeighborIter - n;
    span = LowerSpan < UpperSpan ? LowerSpan : UpperSpan;
  }
//	std::cout << "span: " << span << std::endl; // debug
  if (span < _shortestSpan)
    _shortestSpan = span;
}

void Span::addNumber(std::set<int>::const_iterator beginSet,
                     std::set<int>::const_iterator endSet) {
  _shortestSpan = 1;
  while (*beginSet < *endSet) {
    if (_spanSet.size() == _sizeMax)
      throw std::out_of_range("Span is full");
    _spanSet.insert(*beginSet);
    beginSet++;
  }
}

void Span::addNumber(std::vector<int>::const_iterator beginVec,
                     std::vector<int>::const_iterator endVec) {
  _shortestSpan = 1;
  while (beginVec < endVec) {
    if (_spanSet.size() == _sizeMax)
      throw std::out_of_range("Span is full");
    _spanSet.insert(*beginVec);
    beginVec++;
  }
}

unsigned int Span::shortestSpan() const throw(std::exception) {
  if (_spanSet.size() < 2)
    throw std::out_of_range("Too few elements");
  return _shortestSpan;
}

unsigned int Span::longestSpan() const throw(std::exception) {
  if (_spanSet.size() < 2)
    throw std::out_of_range("Too few elements");
  return *_spanSet.rbegin() - *_spanSet.begin();
}

void Span::setPrint() {
  std::cout << "setPrint+++" << std::endl;
  for (std::set<int>::iterator i = _spanSet.begin(); i != _spanSet.end(); ++i)
    std::cout << *i << std::endl;
  std::cout << "++++++++" << std::endl;
}
