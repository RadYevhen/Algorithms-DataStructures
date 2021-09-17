#pragma once
#include <iostream>

// Based on Linked List because Array based would be limited by space(increasing array will take O(n)) even if use circle array ((tail+1) % 'length of array')
template <class T>
class Queue
{
    private:
        struct Node
        {
            T data;
            Node* next;
        };

        Node* head;
        Node* tail;

        void Print(const Node* node);

    public:
        Queue();
        Queue(const T data);
        ~Queue();
        void Enqueue(const T data);
        void Dequeue();
        bool IsEmpty();
        T GetFirst();
        T GetLast();
        void Print();
};