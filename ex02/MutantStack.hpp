//
// Created by yuumo on 2022/08/12.
//

#ifndef EX02_MUTANTSTACK_HPP
#define EX02_MUTANTSTACK_HPP

#include <stack>

template<class T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() : std::stack<T>() {};
	MutantStack(const MutantStack &mutantStack) : std::stack<T>(mutantStack) {} ;
	MutantStack &operator=(MutantStack &mutantStack) { return std::stack<T>::operator=(mutantStack); };
	~MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator    begin(void) {
		return this->c.begin();
	}
	iterator    end(void) {
		return this->c.end();
	}
	const_iterator begin(void) const {
		return this->c.begin();
	}
	const_iterator end(void) const {
		return this->c.end();
	}
};

//#include "MutantStack.tpp"

#endif //EX02_MUTANTSTACK_HPP
