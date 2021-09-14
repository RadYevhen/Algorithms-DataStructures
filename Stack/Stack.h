#pragma once
#include <iostream>

// List based
template <class T>
class Stack
{
    private:
        struct Node
        {
            T data;
            Node* next;
        };

        Node* top;
    
    public:
        Stack();
        Stack(const T data);
        ~Stack();
        void Push(const T data);
        void Pop();
        T GetTop();
        bool IsEmpty();
        void Print();
};

// // Array based
// template <class T>
// class Stack
// {
//     private:
//         int top;
    
//     public:
//         Stack();
//         Stack(const T data);
//         void Push(const T data);
//         void Pop();
//         Node* GetTop();
//         bool IsEmpty();
// };