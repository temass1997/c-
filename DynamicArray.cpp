#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
	DynamicArray::size = 10;
	data = new int[10];
}

DynamicArray::DynamicArray(int size)
{
	DynamicArray::size = size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = 0;
	}
}

DynamicArray::DynamicArray(int size, int n)
{
	DynamicArray::size = size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = n;
	}
}

DynamicArray::DynamicArray(const DynamicArray & Ar)
{
	size = Ar.size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = Ar.data[i];
	}
}

const int DynamicArray::length()
{
	return size;
}

const int& DynamicArray::operator[](int index)
{
	return data[index];
}

void DynamicArray::resize(int newSize)
{
	int* newdata = new int[newSize];
	for (int i = 0; i < newSize; i++) {
		if (newSize <= size) {
			newdata[i] = data[i];
		} else if(i > size-1) {
			newdata[i] = 0;
		}
	}
	delete[] data;
	size = newSize;
	data = newdata;
}

DynamicArray & DynamicArray::operator=(const DynamicArray & right)
{
	delete[] data;
	size = right.size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = right.data[i];
	}
	return *this;
}

DynamicArray::~DynamicArray()
{
	delete[] data;
}

const bool operator==(const DynamicArray & left, const DynamicArray & right)
{
	if (left.size != right.size) {
		throw 1;
	} else {
		for (int i = 0; i < right.size; i++) {
			if (left.data[i] != right.data[i]) {
				return false;
			}
		}
	}
	return true;
}

const bool operator!=(const DynamicArray & left, const DynamicArray & right)
{
	if (left.size != right.size) {
		throw 1;
	}
	else {
		for (int i = 0; i < right.size; i++) {
			if (left.data[i] == right.data[i]) {
				return false;
			}
		}
	}
	return true;
}

const bool operator<(const DynamicArray & left, const DynamicArray & right)
{
	int minsize = left.size < right.size ? left.size : right.size;
	for (int i = 0; i < minsize; i++) {
		if (left.data[i] >= right.data[i]) {
			return false;
		}
	}
	return true;
}

const bool operator<=(const DynamicArray & left, const DynamicArray & right)
{
	int minsize = left.size < right.size ? left.size : right.size;
	for (int i = 0; i < minsize; i++) {
		if (left.data[i] > right.data[i]) {
			return false;
		}
	}
	return true;
}

const bool operator>(const DynamicArray & left, const DynamicArray & right)
{
	int minsize = left.size < right.size ? left.size : right.size;
	for (int i = 0; i < minsize; i++) {
		if (left.data[i] <= right.data[i]) {
			return false;
		}
	}
	return true;
}

const bool operator>=(const DynamicArray & left, const DynamicArray & right)
{
	int minsize = left.size < right.size ? left.size : right.size;
	for (int i = 0; i < minsize; i++) {
		if (left.data[i] < right.data[i]) {
			return false;
		}
	}
	return true;
}

DynamicArray & operator+(const DynamicArray & left, const DynamicArray & right)
{
	int newsize = left.size + right.size;
	DynamicArray* newArray = new DynamicArray(newsize);
	delete[] newArray->data;
	newArray->data = new int[newsize];
	
	for (int i = 0; i < newsize; i++) {
		if (i < left.size) {
			newArray->data[i] = left.data[i];
		} else {
			newArray->data[i] = right.data[i];
		}
	}
	return *newArray;
}

std::ostream & operator<<(std::ostream & left, const DynamicArray & right)
{
	left << "{ ";
	for (int i = 0; i < right.size; i++) {
		left << right.data[i] << ' ';
	}
	left << '}';
	return left;
}

std::istream & operator>>(std::istream & left, const DynamicArray & right)
{
	std::cout << "Please type your numbers: ";
	for (int i = 0; i < right.size; i++) {
		left >> right.data[i];
	}
	return left;
}
