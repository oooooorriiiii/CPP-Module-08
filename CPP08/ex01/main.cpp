//
// Created by yuumo on 2022/08/02.
//

#include <iostream>
#include <list>
#include <vector>

#include "Span.hpp"

int	main() {

	{
		std::cout << "[TEST]: subject main" << std::endl;
		try
		{
			Span sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

//		sp.setPrint();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;

		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "[TEST]: duplicate elements: all" << std::endl;
		try
		{
			Span sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(6);
			sp.addNumber(6);
			sp.addNumber(6);
			sp.addNumber(6);

//			sp.setPrint();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "[TEST]: duplicate elements: only one element"
		          << std::endl;
		try
		{
			Span sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(6);
			sp.addNumber(11);

//			sp.setPrint();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "[TEST]: Only two element"
		          << std::endl;
		try
		{
			Span sp = Span(2);

			sp.addNumber(6);
			sp.addNumber(3);

//			sp.setPrint();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "[TEST]: 10000 elements" << std::endl;
		try
		{
			Span sp = Span(10000);
			std::vector<int> vector;

			vector.reserve(10000);
			for (int i = 0; i < 10000; ++i)
				vector.push_back(i);

			for (int i = 0; i < 10000; ++i)
				sp.addNumber(vector.at(i));

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "[TEST]: addNumber using range of iterators" << std::endl;
		try
		{
			Span sp = Span(10000);
			std::vector<int> vector;

			vector.reserve(10000);
			for (int i = 0; i < 10000; ++i)
				vector.push_back(i);

			sp.addNumber(vector.begin(), vector.end());

//			sp.setPrint();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "[TEST]: addNumber using range of iterators: Span is full error" << std::endl;
		try
		{
			Span sp = Span(10);
			std::vector<int> vector;

			vector.reserve(12);
			for (int i = 0; i < 12; ++i)
				vector.push_back(i);

			sp.addNumber(vector.begin(), vector.end());

//			sp.setPrint();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "[TEST]: addNumber using range of iterators: Span is few"
		          << std::endl;
		try
		{
			Span sp = Span(10);
			std::vector<int> vector;

			vector.reserve(5);
			for (int i = 0; i < 5; ++i)
				vector.push_back(i);

			sp.addNumber(vector.begin(), vector.end());

//			sp.setPrint();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}


	return 0;
}