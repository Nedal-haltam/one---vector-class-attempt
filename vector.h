
#pragma once
#include<iostream>
using namespace std;

template<class T>
class vector
{
private:
	T* vec;
	int capacity;
	int size;

	void resize(double scale);

public:

	vector(int capacity = 0);
	vector(vector<T>& other);

	~vector();

	void push_back(T val);
	void pop_back();

	T front() const;
	T back()  const;

	void insert(int index, T val);
	void remove(int index);
	bool contains(T& val) const;

	bool is_empty() const;
	void clear();

	int getsize();

	void reverse();

	T& operator[](int index);

	template<class T>
	friend ostream& operator<<(ostream& os, vector<T>& v);

	vector<T>& operator=(vector<T>& other);


};


template<class T>
vector<T>::vector(int capacity)
{
	if (!capacity)
	{
		this->capacity = 8;
		size = 0;
		vec = new T[capacity];

		for (int i = 0; i < capacity; i++)
			vec[i] = NULL;
	}

	else
	{
		this->capacity = capacity;
		size = capacity;
		vec = new T[capacity];

		for (int i = 0; i < capacity; i++)
			vec[i] = NULL;
	}
	
}


template<class T>
vector<T>::vector(vector<T>& other)
{
	*this = other;
}


template<class T>
vector<T>& vector<T>::operator=(vector<T>& other)
{
	if (this == &other) return *this;

	capacity = other.capacity;
	size = other.size;

	vec = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		vec[i] = other.vec[i];
	}

	return *this;
}





template<class T>
vector<T>::~vector()
{
	delete[]vec;
}

template<class T>
void vector<T>::push_back(T val)
{
	if (size == capacity) resize((double)2);

	vec[size++] = val;

}

template<class T>
void vector<T>::pop_back()
{
	if (size <= capacity * 1 / 4) resize((double)0.5);

	if (is_empty()) return;
	size--;

}

template<class T>
T vector<T>::front() const
{
	if (is_empty()) throw string("the vector is empty.");

	return vec[0];
}

template<class T>
T vector<T>::back() const
{
	if (is_empty()) throw string("the vector is empty.");

	return vec[size - 1];
}

template<class T>
int vector<T>::getsize()
{
	return size;
}

template<class T>
bool vector<T>::is_empty() const
{
	return size == 0;
}


template<class T>
void vector<T>::insert(int index, T val)
{
	if (size == capacity) resize((double)2);

	if (index < 0) throw string("index out of range");
	if (index >= size) vec[size++] = val;
	else
	{
		for (int i = 0; i < size - index; i++)
		{
			vec[size - i] = vec[size - i - 1];
		}
		vec[index] = val;
		size++;
	}
	


}



template<class T>
void vector<T>::remove(int index)
{
	if (size <= capacity * 1 / 4) resize((double)0.5);

	if (index < 0 or index >= size) throw string("index out of range");

	for (int i = index; i < size - 1; i++)
	{
		vec[i] = vec[i + 1];
	}
	size--;

}

template<class T>
bool vector<T>::contains(T& val) const
{
	for (int i = 0; i < size; i++)
	{
		if (vec[i] == val) return true;
	}
	return false;
}


template<class T>
void vector<T>::reverse()
{
	for (int i = 0; i < size / 2; i++)
	{
		swap(vec[i], vec[size - i - 1]);
	}
}


template<class T>
void vector<T>::clear()
{
	delete[]vec;
	vec = new T[8];
	capacity = 8;
	size = 0;
}


template<class T>
void vector<T>::resize(double scale)
{
	capacity = int(capacity * scale);
	T* newvector = new T[capacity];

	for (int i = 0; i < size; i++)
	{
		newvector[i] = vec[i];
	}

	delete[]vec;
	vec = newvector;
}





template<class T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	for (int i = 0; i < v.size; i++)
	{
		os << v.vec[i] << " ";
	}
	return os;
}

template<class T>
T& vector<T>::operator[](int index)
{
	if (index < 0) throw string("index out of range");

	return vec[index];
}






