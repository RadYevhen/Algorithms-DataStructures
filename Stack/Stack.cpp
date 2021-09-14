#include "Stack.h"

template <class T>
Stack<T>::Stack()
{
    top = nullptr;
}

template <class T>
Stack<T>::Stack(const T data)
{
    top = new Node();
    top->data = data;
    top->next = nullptr;
}

template <class T>
Stack<T>::~Stack()
{
    if(top == nullptr) { return; }

    Node* temp = top;
    while(temp->next != nullptr)
    {
        temp = temp->next;
        delete top;
        top = temp;
    }

    delete top;
}

template <class T>
void Stack<T>::Push(const T data)
{
    Node* temp = new Node();
    temp->data = data;
    
    if(top == nullptr)
    {
        temp->next = nullptr;
    }
    else
    {
        temp->next = top;
    }
    top = temp;
}

template <class T>
void Stack<T>::Pop()
{
    if(top == nullptr) {return;}
    Node* temp = top->next;
    delete top;
    top = temp;
}

template <class T>
T Stack<T>::GetTop()
{
    return top == nullptr ? : top->data;
}

template <class T>
bool Stack<T>::IsEmpty()
{
    return top == nullptr ? true : false;
}

template <class T>
void Stack<T>::Print()
{
    Node* temp = top;
    while(temp != nullptr)
    {
        std::cout << "|" << temp->data << "|" << std::endl;
        temp = temp->next;
    }
}