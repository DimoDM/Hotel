#pragma once

template<typename T>
class Vector
{
private:
	size_t capacity;
	size_t size;
	T* data;

	void copyFrom(const T&);
	void free();

public:
	Vector();
	Vector(const T&);
	const T& operator=(const T&);
	T& operator[](int);

	void push_back(const T&);

	~Vector();

};