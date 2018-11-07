#ifndef PROCESSOR_CPP
#define PROCESSOR_CPP

#include "Processor.hpp"

template <class T>
void Processor<T>::AddFunction(F<T> f) {
	function_vector.push_back(f);
}

template <class T>
void Processor<T>::removeFunction() {
	function_vector.pop_back();
}

template <class T>
void Processor<T>::clear() {
	function_vector.clear();
}

// Algorithm that computes: f1 o f2 o f3 o ... o fn (t)
template <class T>
T Processor<T>::execute(const T t) {
	std::size_t size = function_vector.size();
	if (size == 0) {
		std::cout << "Exception! No functions to compose and execute!\n";
		return 1;
	}
	T result = function_vector[size - 1](t);
	T temp;
	for (unsigned i = size - 1; i > 0; i = i - 2) {
		if (i == 1) {
			result = function_vector[i - 1](result);
			return result;
		}
		temp = function_vector[i - 1](result);
		result = function_vector[i - 2](temp);
	}
	return result;
}


#endif

// test program 
#include <iostream>
#include "Processor.hpp"

// Free functions 

double exponential(double value) {
	return std::exp(value);
}

double sine(double value) {
	return std::sin(value);
}

double inverse(double value) {
	if (abs(value) > 0.01) return 1 / value;
	else {
		std::cout << "Undefined result!\n\n";
		return 1;
	}
}

int main() {

	// Function object that doubles the input
	std::function<int(const int)> f1 = [](const int a) {
		return a * 2;
	};

	// Populate the processor's function vector with the above doubling function
	Processor<int> processor;

	unsigned N = 5;

	// Populate the processor
	for (unsigned i = 0; i < N; i++) {
		processor.AddFunction(f1);
	}

	// Now exectute with input 1
	// Will compute the Nth power of 2: for N = 5 we expect to get 32
	std::cout << "The " << N << "th power of 2 is : " << processor.execute(1) << "\n\n";

	if (N > 0) {
		// Remove the last function
		processor.removeFunction();

		// Will compute the Nth - 1 power of 2: for N' = 5 - 1 we expect to get 16
		std::cout << "The " << N << "th - 1 power of 2 (2^" << N - 1 << ") is : " << processor.execute(1) << "\n\n";
	}

	// Remove all functions 
	processor.clear();

	// Compute exp(sin [ pi / 5 ])
	Processor<double> processor2;
	processor2.AddFunction(exponential);
	processor2.AddFunction(sine);
	processor2.AddFunction(inverse);

	// Test
	std::cout << "Computing exp(sin [ pi / 5 ]): " << processor2.execute(5.0 / 3.14159) << "\n\n";

	// Clear out processor2
	processor2.clear();	

	return 0;
}