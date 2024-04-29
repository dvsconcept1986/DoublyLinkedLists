#pragma once

#include <iostream>
#define TH template<typename Type>

template<typename Type = int>
class DList
{
private:

	struct node
	{
		node* next, *prev;
		Type data;

		node(Type& _data, node* _prev) : data(_data), prev(_prev), next(nullptr) {}
	};

	int count;
	node* first, *last;

public:
	DList() { first = last = nullptr; count = 0; }
	~DList();

	int GetCount() { return count; }

	void push_back(Type _data);

	Type& operator[](int _index);
	const Type& operator[](int _index) const;
	void Clear();
	void Push_Front(Type _data);
	void Erase(int index);
};



TH
void DList<Type>::push_back(Type _data)
{
	node* n = new node(_data, last);

	if (last)
		last->next = n;
	else
		first = n;

	last = n;

	++count;
}

template<typename Type>
DList<Type>::~DList()
{
	//You will need to fill this out
	Clear();
}

template<typename Type>
Type& DList<Type>::operator[](int _index)
{
	node* temp = first;

	int i = 0;
	for (; i < _index; ++i)
		temp = temp->next;

	return temp->data;
}

template<typename Type>
const Type& DList<Type>::operator[](int _index) const
{
	node* temp = first;

	int i = 0;
	for (; i < _index; ++i)
		temp = temp->next;

	return temp->data;
}

template<typename Type>
void DList<Type>::Clear()
{
	node* current = first;
	while (current != nullptr)
	{
		node* next = current->next;
		delete current;
		current = next;
	}
	count = 0;
	first = last = nullptr;
}

template<typename Type>
void DList<Type>::Push_Front(Type _data)
{
	node* newNode = new node(_data, nullptr); // Create a new node with no previous node

	if (!first) // If the list is empty
	{
		first = last = newNode; // Set both first and last to the new node
	}
	else
	{
		newNode->next = first; // Link the new node to the old first node
		first->prev = newNode; // Link the old first node to the new node
		first = newNode; // Update the first pointer to point to the new node
	}

	++count; // Increment the count of elements in the list
}

template<typename Type>
void DList<Type>::Erase(int index)
{
	if (index < 0 || index >= count) // Check if index is out of bounds
	{
		std::cerr << "Error: Index out of bounds\n";
		return;
	}

	node* current = first;
	for (int i = 0; i < index; ++i) // Traverse to the node at the specified index
	{
		current = current->next;
	}

	if (count == 1) // Special case: Deleting the only node in the list
	{
		delete current;
		first = last = nullptr;
	}
	else if (current == first) // Special case: Deleting the first node
	{
		first = current->next;
		first->prev = nullptr;
		delete current;
	}
	else if (current == last) // Special case: Deleting the last node
	{
		last = current->prev;
		last->next = nullptr;
		delete current;
	}
	else // Generic case: Deleting a node that is neither the first nor the last
	{
		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;
	}

	--count; // Decrement the count of elements in the list
}
