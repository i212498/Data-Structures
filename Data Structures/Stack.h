#pragma once
#include <vector>

template <typename T>

class Stack
{
private:
	std::vector<T> stck;

public:
	void Push(T val);
	void Pop(T& val);
	void Top(T& val);
	bool isEmpty();
	void makeNull();
	int getSize();
};

template <typename T>

void Stack<T>::Push(T val)
{
	stck.push_back(val);
}

template <typename T>

void Stack<T>::Pop(T& val)
{
	if (stck.empty() != true)
	{
		val = stck.back();

		stck.pop_back();
	}
	
}

template <typename T>

void Stack<T>::Top(T& val)
{
	if (stck.empty() != true)
	{
		val = stck.back();
	}
}

template <typename T>

bool Stack<T>::isEmpty()
{
	return stck.empty();
}

template <typename T>

void Stack<T>::makeNull()
{
	stck.clear();
}

template <typename T>

int Stack<T>::getSize()
{
	return stck.size();
}