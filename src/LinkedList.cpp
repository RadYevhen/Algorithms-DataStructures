#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList()
{
	head = new Node();
	head = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(const T data)
{
	head = new Node();
	head->data = data;
	head->next= nullptr;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node* temp;
	while(head != nullptr)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}

template<class T>
void LinkedList<T>::Insert(const T data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = head;
	head = temp;
}

template<class T>
void LinkedList<T>::Insert(const T data, const int position)
{
	if(position <= 0) { return; }

	// New node for insertion
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	if (position == 1)
	{
		newNode->next = head;
		head = newNode;
		return;
	}

	// Find correct Node in required position
	Node* temp = head;
	for(int i = 1; i < position - 1; ++i)
	{
		// Required position can be higher than Nodes - add new Node to the end
		if (temp->next == nullptr)
		{
			break;
		}
		temp = temp->next;
	}

	// New Node should have link to next Node after temp
	// temp Node should have link to new Node
	newNode->next = temp->next;
	temp->next = newNode;
}

template<class T>
void LinkedList<T>::InsertToEnd(const T data)
{
	// Create new node
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = nullptr;

	// Find last node
	Node* temp = head;
	while(temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

template<class T>
void LinkedList<T>::Delete(const int position)
{
	if(position <= 0) { return; }
	Node* temp = head;
	// Deletion of the first Node
	if(position == 1)
	{
		head = temp->next;
		delete temp;
		return;
	}

	// Find Node that one position before needed one
	for(int i = 1; i < position-1; ++i)
	{
		// When required position doesn't exist in the list - nothing to delete
		if(temp->next == nullptr)
		{
			return;
		}
		temp = temp->next;
	}

	// Change reference for found Node
	if (temp->next != nullptr)
	{
		Node* deleteNode = temp->next;
		temp->next = deleteNode->next;

		delete deleteNode;
	}
}

template<class T>
void LinkedList<T>::Reverse()
{
	Node* prev = nullptr;
	Node* curr = head;
	Node* next = curr->next;

	// Go through the list and change links
	while(next != nullptr)
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		next = next->next;
	}

	// Change link of last Node and change head
	curr->next = prev;
	head = curr;
}

template<class T>
void LinkedList<T>::ReverseRecursively()
{
	Node* node = head;
	ReverseRecursively(node);
	node->next = nullptr;
}

template<class T>
void LinkedList<T>::ReverseRecursively(Node* node)
{
	if(node->next == nullptr)
	{
		head = node;
		return;
	}
	ReverseRecursively(node->next);
	Node* temp = node->next;
	temp->next = node;
}

template<class T>
void LinkedList<T>::Print()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}

template<class T>
void LinkedList<T>::PrintReversed()
{
	PrintReversed(head);
}

template<class T>
void LinkedList<T>::PrintReversed(Node* node)
{
	if(node->next == nullptr)
	{
		std::cout << node->data << " ";
		return;
	}
	PrintReversed(node->next);
	std::cout << node->data << " ";
}
