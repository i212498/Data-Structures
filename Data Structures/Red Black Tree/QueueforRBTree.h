// Do Not touch this code
#pragma once
#include <iostream>

using namespace std;

template <class T>

class QueueNode
{
public:
	T data;
	QueueNode<T>* next;

	QueueNode()
	{
		data = 0;
		next = NULL;
	}

	QueueNode(T d)
	{
		data = d;
		next = NULL;

	}

};

template <class T>

class RBQueue
{
public:

	QueueNode<T>* front;
	QueueNode<T>* rear;

	RBQueue()
	{
		front = NULL;
		rear = NULL;
	}

	bool isEmpty()
	{
		if (front == NULL && rear == NULL)
		{
			return true;
		}
		return false;
	}

	void enqueue(T d)
	{
		QueueNode<T>* temp = new QueueNode<T>(d);

		temp->data = d;
		temp->next = NULL;

		if (isEmpty() == true)
		{
			front = temp;
			rear = temp;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
	}

	T dequeue()
	{
		if (isEmpty() == true)
		{
			return 0;
		}

		if (isEmpty() == false && front == rear)
		{
			QueueNode<T>* temp = new QueueNode<T>(0);	//(0);

			temp = front;

			front = front->next;

			rear = rear->next;

			T x = temp->data;

			delete temp;

			return x;
			
		}

		if (isEmpty() == false && front != rear)
		{
			QueueNode<T>* temp = new QueueNode<T>(0);

			temp = front;

			front = front->next;

			T x = temp->data;

			delete temp;

			return x;
		}
	}

	T Front()
	{
		if (isEmpty() == true)
		{
			return NULL;
		}
		else
		{
			T x = 0;

			x = front->data;

			return x;
		}

	}

	void print()
	{
		if (isEmpty() == true)
		{
			return;
		}

		if (front == rear)
		{
			std::cout << front->data << "\n";

			return;
		}

		QueueNode<T>* temp = front;

		while (temp != rear)
		{
			std::cout << temp->data << "\n";

			temp = temp->next;
		}

		std::cout << temp->data << "\n";
	}
};


