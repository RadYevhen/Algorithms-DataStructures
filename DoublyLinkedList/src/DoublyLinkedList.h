#pragma once
#include <iostream>

template<class T>
class DoublyLinkedList
{
	private:
		struct Node
		{
			T data;
			Node* next;
			Node* prev;
		};

		Node* head;
		Node* tail;

		Node* CreateNode();
		Node* CreateNode(const T& data);
		void CreateTail(const T& data);

	public:
		DoublyLinkedList();
		DoublyLinkedList(const T& data);
		~DoublyLinkedList();
		void InsertAtBegin(const T& data);
		void InsertAtEnd(const T& data);
		void InsertAtPosition(const T& data, const int& position);
		void DeleteFromBegin();
		void DeleteFromEnd();
		void DeleteFromPosition(const int& position);
		void DeleteByData(const T& data, const bool isAllEntries = true, const bool isFromLeft = true);
		void Print();
		void PrintReversed();
};
