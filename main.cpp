#include <iostream>
#include "Queue.cpp"

using namespace std;

int main()
{
    Queue<int>* queue = new Queue<int>();

    cout << queue->IsEmpty() << endl; // 1

    queue->Enqueue(3); // 3
    queue->Enqueue(7); // 3 7
    queue->Enqueue(6); // 3 7 6
    queue->Enqueue(8); // 3 7 6 8 
    queue->Enqueue(1); // 3 7 6 8 1
    queue->Print(); // -> 1 8 6 7 3 ->

    queue->Dequeue(); // 7 6 8 1
    queue->Dequeue(); // 6 8 1
    queue->Print(); // -> 1 8 6 ->

    cout << queue->GetFirst() << endl; // 6
    cout << queue->GetLast() << endl; // 1
    
    cout << queue->IsEmpty() << endl; // 0

    delete queue;
    return 0;
}