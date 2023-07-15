#pragma once
#include "LinkedList.h"

// remap

template <typename T>

class Queue
{
private:
	Node<T>* front;
	Node<T>* rear;
	int size;

public:
	Queue();

	
	void enqueue(T val);
	void dequeue(T &retnval);
	bool isEmpty();
	void makeNull();
	bool isQueued(T val);
	int getSize();

	~Queue();
};

template <typename T>

Queue<T>::Queue()
{
	front = NULL;
	rear = NULL;
	size = 0;
}

template <typename T>

bool Queue<T>::isEmpty()
{
	if (front == NULL && rear == NULL)
	{
		return true;
	}

	return false;
}


template <typename T>

void Queue<T>::enqueue(T val)
{
	Node<T>* toenqueue = new Node<T>;

	toenqueue->data = val;

	toenqueue->next = NULL;

	size++;
	
	if (isEmpty() == true)
	{
		front = toenqueue;
		rear = toenqueue;
		
		return;
	}

	rear->next = toenqueue;

	rear = toenqueue;
}

template <typename T>

void Queue<T>::dequeue(T &retnval)
{
	if (isEmpty() == true)
	{
		return;
	}

	size--;

	if (front == rear)
	{
		retnval = front->data;

		delete front;

		front = NULL;
		rear = NULL;

		return;

	}

	retnval = front->data;

	Node<T>* temp = front;

	front = front->next;

	delete temp;

}

template <typename T>

void Queue<T>::makeNull()
{
	T temp;
	
	while (isEmpty() != true)
	{
		dequeue(temp);
	}
}

template <typename T>

bool Queue<T>::isQueued(T val)
{
	if (isEmpty() == true)
	{
		return false;
	}

	Node<T>* temp = front;

	while (temp != NULL)
	{
		if (temp->data == val)
		{
			return true;
		}

		temp = temp->next;
	}

	return false;
}

template <typename T>

int Queue<T>::getSize()
{
	return this->size;
}

template <typename T>

Queue<T>::~Queue()
{
	makeNull();
}






