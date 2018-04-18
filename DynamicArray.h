#pragma once
#include <iostream>

class DynamicArray {
	int* data;
	int size;
public:
	DynamicArray();
	DynamicArray(int size);
	DynamicArray(int size, int n);
	DynamicArray(const DynamicArray& Ar);
	DynamicArray(DynamicArray&& Ar);

	const int length();
	const int& operator[] (int index);

	void resize(int newSize);

	DynamicArray& operator=(const DynamicArray& right);
	DynamicArray& operator=(DynamicArray&& right);

	friend const bool operator==(const DynamicArray& left, const DynamicArray& right);
	friend const bool operator!=(const DynamicArray& left, const DynamicArray& right);

	friend const bool operator<(const DynamicArray& left, const DynamicArray& right);
	friend const bool operator<=(const DynamicArray& left, const DynamicArray& right);
	friend const bool operator>(const DynamicArray& left, const DynamicArray& right);
	friend const bool operator>=(const DynamicArray& left, const DynamicArray& right);

	friend DynamicArray& operator+(const DynamicArray& left, const DynamicArray& right);

	friend std::ostream& operator<<(std::ostream &left, const DynamicArray& right);
	friend std::istream& operator>>(std::istream &left, const DynamicArray& right);

	~DynamicArray();
};
