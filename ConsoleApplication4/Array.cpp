#include "Array.h"

Array::Array()
{
	_size = _DEFULTSIZE;
	_data = new unsigned int[_DEFULTSIZE];
}

Array::Array(unsigned int size)
{
	_size = size;
	_data = new unsigned int[_size] {};
}

Array::~Array()
{
	delete[] _data;
	_data = nullptr;
}

ErrorsCode Array::resize(unsigned int newSize) {
	if (newSize <= _size) return ErrorsCode::INVALID_SIZE;

	unsigned int* newData = new unsigned int[newSize] {};

	for (unsigned int i = 0; i < _size && i < newSize; ++i) {
		newData[i] = _data[i];
	}

	delete[] _data;
	_data = newData;
	_size = newSize;

	return ErrorsCode::SUCCESS;
}

ErrorsCode Array::add(unsigned int index, int value) {
	if (index >= _size) return ErrorsCode::INVALID_INDEX;

	_data[index] = value;

	return ErrorsCode::SUCCESS;
}

ErrorsCode Array::remove(unsigned int index) {
	if (index >= _size) return ErrorsCode::INVALID_INDEX;

	_data[index] = 0;

	return ErrorsCode::SUCCESS;
}

long int Array::find(int value) {
	for (unsigned int i = 0; i < _size; ++i) {
		if (_data[i] == value) return i;
	}

	return -1;
}

void Array::print() {
	for (unsigned int i = 0; i < _size; ++i) {
		std::cout << _data[i] << " ";
	}
	std::cout << std::endl;
}