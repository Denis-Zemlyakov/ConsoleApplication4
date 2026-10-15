#pragma once
#include <iostream>
#include "Errors.h"

class Array
{
private:
	static const unsigned int _DEFULTSIZE = 16;
	unsigned int _size;
	unsigned int* _data;

public:
	Array();
	Array(unsigned int size);
	~Array();
	ErrorsCode resize(unsigned int newSize);
	ErrorsCode add(unsigned int index, int value);
	ErrorsCode remove(unsigned int index);
	long int find(int value);
	void print();
};