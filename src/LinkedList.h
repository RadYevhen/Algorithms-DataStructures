#pragma once
#include <iostream>

template<class T>
class LinkedList
{
	private:
		struct Node
		{
			T data;
			Node* next;
		};

		Node* head;

		void PrintReversed(Node* node);
		void ReverseRecursively(Node* node);

	public:
		LinkedList();
		LinkedList(const T data);
		~LinkedList();
		void Insert(const T data);
		void Insert(const T data, const int position);
		void InsertToEnd(const T data);
		void Delete(const int position);
		void Reverse();
		void ReverseRecursively();
		void Print();
		void PrintReversed();
};
