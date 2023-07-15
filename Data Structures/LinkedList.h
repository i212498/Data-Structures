#pragma once

template <typename T>

struct Node
{
	T data;
	Node* next;
};

template <typename T>

class LinkedList
{
private:
	Node<T>* head;
	int size;
public:
	LinkedList();
	bool isEmpty();
	void insertAtTail(T val);
	void insertAtHead(T val);
	void insertAtIndex(T val, int index);	//starts at 0
	int findNode(T val);
	bool deleteNode(T val);
	void printList();
	int getSize();

	~LinkedList();
};

template <typename T>

LinkedList<T>::LinkedList()
{
	this->head = NULL;
	size = 0;
}

template <typename T>

bool LinkedList<T>::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}

	return false;
}

template <typename T>

void LinkedList<T>::insertAtTail(T val)
{
	Node<T>* toinsert = new Node<T>;

	toinsert->data = val;

	toinsert->next = NULL;

	if (isEmpty() == true)
	{
		head = toinsert;

		size++;

		return;
	}

	Node<T>* nodeptr = head;

	while (nodeptr->next != NULL)
	{
		nodeptr = nodeptr->next;
	}

	nodeptr->next = toinsert;

	size++;
}


template <typename T>

void LinkedList<T>::insertAtHead(T val)
{
	Node<T>* toinsert = new Node<T>;

	toinsert->data = val;

	toinsert->next = head;

	head = toinsert;

	size++;
	
}

template <typename T>

void LinkedList<T>::insertAtIndex(T val, int index)
{
	if (index == 0)
	{
		this->insertAtHead(val);

		return;
	}
	
	if (index < 0 || (index > 0 && head == NULL))
	{
		return;
	}

	Node<T>* toinsert = new Node<T>;

	toinsert->data = val;
	
	Node<T>* nodeptr = head;

	for (int i = 0; i < index - 1 && nodeptr->next != NULL; i++)
	{
		nodeptr = nodeptr->next;
	}

	if (nodeptr->next != NULL)
	{
		toinsert->next = nodeptr->next;

		nodeptr->next = toinsert;

		size++;
	}

	
}

template <typename T>

int LinkedList<T>::findNode(T val)
{
	if (isEmpty() == true)
	{
		return -1;
	}

	Node<T>* nodeptr = head;

	int index = 0;

	while (nodeptr != NULL)
	{
		if (nodeptr->data == val)
		{
			return index;
		}

		index++;

		nodeptr = nodeptr->next;
	}

	return -1;

}

template <typename T>

bool LinkedList<T>::deleteNode(T val)
{
	if (isEmpty() == true)
	{
		return false;
	}

	if (head->data == val)
	{
		Node<T>* temp = head;

		head = head->next;

		delete temp;

		size--;

		return true;
	}

	Node<T>* nodeptr = head;

	while (nodeptr != NULL)
	{
		if (nodeptr->next->data == val)
		{
			Node<T>* temp = nodeptr->next;

			nodeptr->next = nodeptr->next->next;

			delete temp;

			size--;

			return true;
		}

		nodeptr = nodeptr->next;
	}

	return false;

}


template <typename T>

void LinkedList<T>::printList()
{
	if (isEmpty() == true)
	{
		return;
	}

	Node<T>* nodeptr = head;

	while (nodeptr != NULL)
	{
		std::cout << nodeptr->data << " ";

		nodeptr = nodeptr->next;
	}

	std::cout << "\n";
}

template <typename T>

int LinkedList<T>::getSize()
{
	return this->size;
}


template <typename T>

LinkedList<T>::~LinkedList()
{
	if (isEmpty() == true)
	{
		return;
	}

	Node<T>* temp;
	
	while (head != NULL)
	{
		temp = head;

		head = head->next;

		delete temp;
	}

	size = 0;
}