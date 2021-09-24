#include <iostream>
#include "BinarySearchTree.cpp" // To include .h just build all files together

using namespace std;

int main()
{
    BinarySearchTree<int>* bst = new BinarySearchTree<int>();

    bst->Insert(5); // 5
    bst->Insert(4); // 5 4
    bst->Insert(6); // 5 6
    bst->Insert(3); // 5 4 3
    bst->Insert(5); // 5 4 3 5
    bst->Insert(11); // 5 6 11
    bst->Insert(1); // 5 4 3 5 1
    bst->Print(); // 5 4 3 1 - - - 5 - - 6 - 11 - - 

    cout << bst->Search(6) << endl; // 1
    cout << bst->Search(7) << endl; // 0

    cout << "Min: " << bst->GetMin() << endl; // 1
    cout << "Max: " << bst->GetMax() << endl; // 11

    cout << "Height: " << bst->GetTreeHeight() << endl; // 3

    bst->Delete(11);
    bst->Print(); // 5 4 3 1 - - - 5 - - 6 - -
    bst->Delete(0);
    bst->Print(); // 5 4 3 1 - - - 5 - - 6 - -
    bst->Delete(3);
    bst->Print(); // 5 4 - 5 - - 6 - -

    bst->PrintByLevel(); // 5 4 6 5

    cout << "Is tree BST: " << bst->isBST() << endl << endl; // 1

    delete bst;

//_______________________________________________________________________________________

    BinarySearchTree<int>* bst1 = new BinarySearchTree<int>(10);
    
    // 10 -> 8 15 -> 6 9 11 17 -> 3
    bst1->Insert(15);
    bst1->Insert(8);
    bst1->Insert(6);
    bst1->Insert(3);
    bst1->Insert(9);
    bst1->Insert(11);
    bst1->Insert(17);

    bst->Print(); // 10 8 6 3 - - - 9 - - 15 11 - - 17 - -
    cout << "Is tree BST: " << bst->isBST() << endl; // 1

    // Node with one way
    bst1->DeleteExactNode(6); 
    bst->Print(); // 10 8 3 - - 9 - - 15 11 - - 17 - -
    cout << "Is tree BST: " << bst->isBST() << endl; // 1

    // Node does't exist - nothing happened
    bst1->DeleteExactNode(6); // Node does't exist - nothing happened
    bst->Print(); // 10 8 3 - - 9 - - 15 11 - - 17 - -
    cout << "Is tree BST: " << bst->isBST() << endl; // 1

    // Leaf Node
    bst1->DeleteExactNode(3); 
    bst->Print(); // 10 8 - 9 - - 15 11 - - 17 - -
    cout << "Is tree BST: " << bst->isBST() << endl; // 1

    // Node with two ways
    bst1->Insert(20); 
    bst1->Insert(16); 
    bst1->DeleteExactNode(16); 
    bst->Print(); // 10 8 - 9 - - 15 11 - - 17 - 20 - -
    bst1->DeleteExactNode(15); 
    bst->Print(); // 10 8 - 9 - - 17 11 - - 20 - -
    cout << "Is tree BST: " << bst->isBST() << endl; // 1

    delete bst1;

    return 0;
}