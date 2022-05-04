#pragma once
#include<exception>

template<typename T>
class Vector
{
private:
	size_t capacity;
	size_t size;
	T* data;

	void copyFrom(const Vector&);
	void free();
	void resize();

public:
	Vector();
	Vector(const Vector&);
	const T& operator=(const Vector&);
	T& operator[](int);
	size_t getSize();

	void push_back(const T&);

	~Vector();

};

template<typename T>
void Vector<T>::copyFrom(const Vector& vec)
{
	capacity = vec.capacity;
	size = vec.size;
	data = new T[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = vec.data[i];
	}
}

template<typename T>
void Vector<T>::free()
{
	delete[] data;
}

template<typename T>
void Vector<T>::resize()
{
	size++;
	if (size >= capacity) {
		T* newData = new T[capacity * 2];
		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		free();
		data = newData;
		capacity *= 2;
	}
}

template<typename T>
Vector<T>::Vector()
{
	capacity = 10;
	size = 0;
	data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector& vec)
{
	copyFrom(vec);
}

template<typename T>
const T& Vector<T>::operator=(const Vector& vec)
{
	if (this != &vec) {
		free();
		copyFrom(vec);
	}
	return *this;
}

template<typename T>
T& Vector<T>::operator[](int index)
{
	if (index < size) return data[index];
	else throw new std::exception("out of bounds");
}

template<typename T>
size_t Vector<T>::getSize()
{
	return size;
}

template<typename T>
void Vector<T>::push_back(const T& el)
{
	data[size] = el;
	resize();
}

template<typename T>
Vector<T>::~Vector()
{
	free();
}
