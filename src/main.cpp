// Implementation of Linked intList data structure
#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main()
{
	LinkedList<int>* intList = new LinkedList<int>();

	intList->Insert(3);  // 3
	intList->Insert(7);  // 7 3
	intList->Insert(4);  // 4 7 3
	intList->Insert(2);  // 2 4 7 3
	intList->Insert(11); // 11 2 4 7 3
	intList->InsertToEnd(22); // 11 2 4 7 3 22

	intList->Delete(3); // 11 2 7 3 22
	intList->Delete(24); // 11 2 7 3 22 - same because 24 not exist
	intList->Delete(0); // 11 2 7 3 22 - same
	intList->Delete(-44); // 11 2 7 3 22 - same

	intList->Print();
	cout << endl;

	intList->PrintReversed(); // 22 3 7 2 11
	cout << endl;

	intList->ReverseRecursively(); // 22 3 7 2 11
	intList->Print();
	cout << endl;

	delete intList;

	cout << endl;

//****************************************************************************************
	LinkedList<char>* charList = new LinkedList<char>();

	charList->Insert('c'); // c
	charList->Insert('b'); // b c
	charList->Insert('a'); // a b c
	charList->Insert('!', 3); // a b ! c

	charList->Delete(4); // a b !
	charList->Delete(4); // a b ! - same

	charList->Print();
	cout << endl;

	charList->Reverse(); // ! b a
	charList->Print();
	cout << endl;
	charList->ReverseRecursively(); // a b !
	charList->Print();
	cout << endl;

	delete charList;
	return 0;
}
