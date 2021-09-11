#include "DoublyLinkedList.h"

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = CreateNode();
	tail = nullptr;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const T& data)
{
	head = CreateNode();
	Node* first = CreateNode(data);
	head->next = first;
	first->prev = head;
	tail = nullptr;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	if (head->next == nullptr)
	{
		delete head;
		return;
	}
	// Delete all Nodes apart from last
	Node* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
	// Delete Last Node
	delete head;
	
}

template <class T>
typename DoublyLinkedList<T>::Node *DoublyLinkedList<T>::CreateNode()
{
	Node *node = new Node();
	node->next = nullptr;
	node->prev = nullptr;
	return node;
}

template <class T>
typename DoublyLinkedList<T>::Node *DoublyLinkedList<T>::CreateNode(const T& data)
{
	Node *node = new Node();
	node->data = data;
	node->next = nullptr;
	node->prev = nullptr;
	return node;
}

template <class T>
void DoublyLinkedList<T>::CreateTail(const T& data)
{
	tail = CreateNode(data);
	tail->prev = head;
	head->next = tail;
}

template <class T>
void DoublyLinkedList<T>::InsertAtBegin(const T& data)
{
	// When only one Node in the List - Create Tail and link with head
	if(head->next == nullptr)
	{
		CreateTail(data);
		return;
	}

	Node* newNode = CreateNode(data);
	newNode->prev = head;
	newNode->next = head->next;
	head->next->prev = newNode; // to next Node after Head assign newNode as prev
	head->next = newNode;
}

template <class T>
void DoublyLinkedList<T>::InsertAtPosition(const T& data, const int& position)
{
	if(position <= 0){return;}

	// Insert at begin
	if(position == 1)
	{
		InsertAtBegin(data);
		return;
	}

	// When only one Node in the List - Create Tail and link with head
	if(head->next == nullptr)
	{
		CreateTail(data);
		return;
	}

	Node* newNode = CreateNode(data);

	// Start from first Node(after head) until one position back than needed
	Node* temp = head->next;
	for(int i = 1; i < position - 1; ++i)
	{
		// When length of List less then provided position - insert at end
		if(temp->next == nullptr)
		{
			InsertAtEnd(data);
			return;
		}

		temp = temp->next;
	}
	
	// insert newNoed beetween temp and temp->next
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next->prev = newNode; // Link next Node after 'temp' to 'newNode'
	temp->next = newNode;
}

template <class T>
void DoublyLinkedList<T>::InsertAtEnd(const T& data)
{
	// When only one Node in the List - Create Tail and link with head
	if(head->next == nullptr)
	{
		CreateTail(data);
		return;
	}

	// Create new Node
	Node* newNode = CreateNode(data);

	// Add this node after Tail and change Tail
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
}

template <class T>
void DoublyLinkedList<T>::DeleteFromBegin()
{
	if (head->next == nullptr) { return; }
	
	Node* first = head->next;
	head->next = first->next;
	delete first;
	if(head->next == nullptr)
	{
		tail = nullptr;
		return;
	}
	head->next->prev = head; // Link second Node with Head
}

template <class T>
void DoublyLinkedList<T>::DeleteFromPosition(const int& position)
{
	if(head->next == nullptr || position <= 0){return;}
	if(position == 1)
	{ 
		DeleteFromBegin(); 
		return;
	}

	//Find needed Node
	Node* deleteNode = head->next;
	for(int i = 1; i < position; ++i)
	{
		deleteNode = deleteNode->next;
		// In case deleteNode is NULL - return because List has less length than required position
		if(deleteNode == nullptr){return;}
	}

	// When deleteNode = last Node in the List
	if (deleteNode == tail)
	{
		DeleteFromEnd();
		return;
	}
	// When deleteNode somewhere in the middle of the List
	deleteNode->prev->next = deleteNode->next;
	deleteNode->next->prev = deleteNode->prev;
	delete deleteNode;
}

template <class T>
void DoublyLinkedList<T>::DeleteFromEnd()
{
	if(tail == nullptr) {return;}

	Node* temp = tail->prev; 
	temp->next = nullptr;
	delete tail;
	tail = temp;
}

template <class T>
void DoublyLinkedList<T>::DeleteByData(const T& data, const bool isAllEntries, const bool isFromLeft)
{
	if(head->next == nullptr){return;}
	Node* temp;
	Node* deleteNode;

	//From left to right
	if(isFromLeft == true)
	{
		temp = head->next;
		while(temp != nullptr)
		{
			if(temp->data == data)
			{
				if (temp == head->next) { 
					DeleteFromBegin(); 
					if(isAllEntries == false){return;}
					temp = head->next; 
					continue; }
				else if (temp == tail) { DeleteFromEnd(); return; }
				else 
				{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					deleteNode = temp;
					temp = temp->next;
					delete deleteNode;
					if(isAllEntries == false){return;}
					continue;
				}
			}
			temp = temp->next;
		}
	}
	else
	{
		temp = tail;
		while(temp != head)
		{
			if(temp->data == data)
			{
				if (temp == tail) { 
					DeleteFromEnd();
					if(isAllEntries == false){return;}
					temp = tail; 
					continue; }
				else if (temp == head->next) { DeleteFromBegin(); return; }
				else 
				{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					deleteNode = temp;
					temp = temp->prev;
					delete deleteNode;
					if(isAllEntries == false){return;}
					continue;
				}
			}
			temp = temp->prev;
		}
	}
}

template <class T>
void DoublyLinkedList<T>::Print()
{
	if(head->next == nullptr) { return; }
	// Start to Print from next after head node
	Node *temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
		std::cout << temp->data << " ";
	}
}

template <class T>
void DoublyLinkedList<T>::PrintReversed()
{
	if(tail == nullptr){return;}

	Node*temp = tail;
	while(temp != head)
	{
		std::cout << temp->data << " ";
		temp = temp->prev;
	}
}