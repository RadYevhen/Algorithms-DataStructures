#include "Queue.h"

template <class T>
Queue<T>::Queue()
{
    head = tail = nullptr; 
}

template <class T>
Queue<T>::Queue(const T data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    head = tail = temp;
}

template <class T>
Queue<T>::~Queue()
{
    Node* temp = head;
    while(head != nullptr)
    {
        head = temp->next;
        delete temp;
        temp = head;
    }
}

template <class T>
void Queue<T>::Enqueue(const T data)
{
    // Create new Node
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    // when head is NULL - tail is also NULL
    if(head == nullptr)
    {
        head = tail = temp;
        return;
    }
    // Add Node at end
    tail->next = temp;
    tail = temp;
}

template <class T>
void Queue<T>::Dequeue()
{
    // Nothing to remove
    if(head == nullptr){return;}

    // Remove at begin because of FIFO(First In First Out)
    Node* temp = head->next;
    delete head;
    head = temp;
}

template <class T>
bool Queue<T>::IsEmpty()
{
    return head == nullptr ? true : false;
}

template <class T>
T Queue<T>::GetFirst()
{
    return head->data;
}

template <class T>
T Queue<T>::GetLast()
{
    return tail->data;
}

template <class T>
void Queue<T>::Print()
{
    if(head == nullptr){return;}
    // Pring List in format: -> 1 2 3 ->
    // Since first element should be last and last should be first - print in revers format using recursion
    Node* temp = head;
    
    std::cout << "-> ";

    Print(temp);
    
    std::cout << "->" << std::endl;
}

template <class T>
void Queue<T>::Print(const Node* node)
{
    if(node == nullptr){return;}
    Print(node->next);
    std::cout << node->data << " ";
}