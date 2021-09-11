#include <iostream>
#include "DoublyLinkedList.cpp"
using namespace std;

int main()
{
	DoublyLinkedList<int>* intList = new DoublyLinkedList<int>();

	intList->InsertAtEnd(1); // 1
	intList->InsertAtEnd(2); // 1 2
	intList->InsertAtBegin(3); // 3 1 2
	intList->InsertAtPosition(5, 89); // 3 1 2 5
	intList->InsertAtPosition(7, 2); // 3 7 1 2 5
	intList->InsertAtPosition(44, 1); // 44 3 7 1 2 5
	intList->InsertAtPosition(44, 3); // 44 3 44 7 1 2 5
	intList->InsertAtPosition(99, 99); // 44 3 44 7 1 2 5 99
	intList->InsertAtPosition(99, 1); // 99 44 3 44 7 1 2 5 99
	intList->Print();
	cout << endl;
	intList->DeleteFromBegin(); // 44 3 44 7 1 2 5 99
	intList->DeleteFromBegin(); // 3 44 7 1 2 5 99
	intList->DeleteFromBegin(); // 44 7 1 2 5 99
	intList->DeleteFromEnd(); // 44 7 1 2 5
	intList->DeleteFromPosition(1); // 7 1 2 5
	intList->Print();
	cout << endl;
	intList->DeleteByData(3); // 7 1 2 5
	intList->DeleteByData(5); // 7 1 2
	intList->InsertAtEnd(2); // 1 2 2
	intList->InsertAtBegin(3); // 3 1 2 2
	intList->InsertAtBegin(3); // 3 3 1 2 2
	intList->InsertAtEnd(7); // 3 3 1 2 2 7
	intList->InsertAtBegin(7); // 7 3 3 1 2 2 7
	intList->InsertAtBegin(7); // 7 7 3 3 1 2 2 7
	intList->InsertAtPosition(7, 5); // 7 7 3 3 7 1 2 2 7
	intList->DeleteByData(7); // 3 3 1 2 2
	intList->InsertAtEnd(3); // 3 3 1 2 2 3
	intList->DeleteByData(3, false, false); // 3 3 1 2 2
	intList->DeleteByData(3, false); // 3 1 2 2
	intList->DeleteByData(2); // 3 1
	intList->Print();
	cout << endl;

	delete intList;
	return 0;
}
