#include "BinarySearchTree.h"

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const T data)
{
    root = CreateEmptyBSTNode(data);
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    Delete(root);
}

template <class T>
typename BinarySearchTree<T>::BST_Node* BinarySearchTree<T>::CreateEmptyBSTNode(const T data)
{
    BST_Node* node = new BST_Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

template <class T>
bool BinarySearchTree<T>::Search(const T data)
{
    return Search(root, data);
}

template <class T>
bool BinarySearchTree<T>::Search(const BST_Node* currentNode, const T data)
{
    if(currentNode == nullptr) { return false; }
    else if( currentNode->data == data ) { return true; }
    else if ( data < currentNode->data ) // left
    {
        return Search(currentNode->left, data);
    }
    else // right
    {
        return Search(currentNode->right, data);
    }
}

template <class T>
void BinarySearchTree<T>::Insert(const T data)
{
    // Check each and every node recursively for adding
    root = Insert(root, data);
}

template <class T>
typename BinarySearchTree<T>::BST_Node* BinarySearchTree<T>::Insert(BST_Node* currentNode, const T data)
{
    if(currentNode == nullptr)
    {
        currentNode = CreateEmptyBSTNode(data);
    }
    // insert to left side of the tree if data >= exist data in Node, otherwise insert to right side of the tree
    else if ( data <= currentNode->data ) // left
    {
        currentNode->left = Insert(currentNode->left, data);
    }
    else if ( data > currentNode->data )
    {
        currentNode->right = Insert(currentNode->right, data);
    }
    return currentNode;
}

template <class T>
void BinarySearchTree<T>::Delete(const T data)
{
    // Check if data exist in the tree
    if(!Search(data)){return;}

    // If case data equal to root data - delete all tree
    if(root->data == data) Delete(root);
    // Otherwise - choose right direction for deletion
    else if(data < root->data) Delete(root->left, data, false);
    else if(data > root->data) Delete(root->right, data, false);
}

template <class T>
void BinarySearchTree<T>::Delete(BST_Node* &currentNode)
{
    if(currentNode == nullptr) return;
    if(currentNode->left == nullptr && currentNode->right == nullptr) 
    { 
        delete currentNode; 
        currentNode = nullptr; // Rubbish appears inside the Node after delete
        return; 
    }
    Delete(currentNode->left);
    Delete(currentNode->right);
    delete currentNode;
    currentNode = nullptr; // Rubbish appears inside the Node after delete
}

template <class T>
void BinarySearchTree<T>::Delete(BST_Node* &currentNode, const T &data, bool isForDelete)
{
    if(currentNode == nullptr) return;
    if( currentNode->left == nullptr && currentNode->right == nullptr && isForDelete == true )
    {
        delete currentNode;
        currentNode = nullptr; // Rubbish appears inside the Node after delete
        return;
    }
    // When data in the Node equal required data - remove current Node and all child Nodes
    if(currentNode->data == data)
    {
        Delete(currentNode->left, data, true);
        Delete(currentNode->right, data, true);
        delete currentNode;
        currentNode = nullptr; // Rubbish appears inside the Node after delete
    }
    // If data not equal - choose right direction
    else
    {
        if(data < currentNode->data) Delete(currentNode->left, data, false);
        else if(data > currentNode->data) Delete(currentNode->right, data, false);
    }
}

template <class T>
T BinarySearchTree<T>::GetMin()
{
    BST_Node* temp = root;
    return GetMin(temp);
} 

template <class T>
T BinarySearchTree<T>::GetMin(const BST_Node* currentNode)
{
    if ( currentNode->left == nullptr ) { return currentNode->data; }
    return GetMin(currentNode->left);
} 

template <class T>
T BinarySearchTree<T>::GetMax()
{
    BST_Node* temp = root;
    return GetMax(temp);
}

template <class T>
T BinarySearchTree<T>::GetMax(const BST_Node* currentNode)
{
    if ( currentNode->right == nullptr ) { return currentNode->data; }
    return GetMax(currentNode->right);
}

template <class T>
int BinarySearchTree<T>::GetTreeHeight()
{
    return GetTreeHeight(root);
}

template <class T>
int BinarySearchTree<T>::GetTreeHeight(const BST_Node* currentNode)
{
    if(currentNode == nullptr) return -1;
    if(currentNode->left == nullptr && currentNode->right == nullptr) { return 0; }
    int heightLeft = GetTreeHeight(currentNode->left) + 1;
    int heightRight = GetTreeHeight(currentNode->right) + 1;

    return heightLeft >= heightRight ? heightLeft : heightRight;
}

template <class T>
void BinarySearchTree<T>::Print()
{
    Print(root);
    std::cout << std::endl;
}

template <class T>
void BinarySearchTree<T>::Print(const BST_Node* currentNode)
{
    if( currentNode == nullptr) { std::cout << "_ "; return; }

    std::cout << currentNode->data << " ";
    Print(currentNode->left);
    Print(currentNode->right);
}

template <class T>
void BinarySearchTree<T>::PrintByLevel()
{
    // Breadth search - required additional space for Queue to store Nodes
    std::queue<BST_Node*> nodesQueue;
    nodesQueue.push(root);
    // print data, add left and right to queue, remove node that was printed
    while (!nodesQueue.empty())
    {
        BST_Node* temp = nodesQueue.front();
        std::cout << temp->data << " ";
        if(temp->left != nullptr) nodesQueue.push(temp->left);
        if(temp->right != nullptr) nodesQueue.push(temp->right);
        nodesQueue.pop();
    }
    std::cout << std::endl;
}

template <class T>
bool BinarySearchTree<T>::isBST()
{
    // Brute Force - O(N^2)
    // return isBST(root, root->data);

    // The best - O(N) - O(N) for list creation + O(N) for checking is sorted or not
    // Go through tree by <call left><read data><call right> AND add data to the List(in BST List will be sorted). Loop by array checking for [i] > [i+1] - in this case false
    std::list<T> nodes;
    isBSTBest(root, nodes); // O(N)
    return std::is_sorted(nodes.begin(), nodes.end()); // O(N)
    
    // Manual check is list sorted or not
    // int i = 1;
    // for (auto it = nodes.begin(); it != nodes.end(); ++it)
    // {
    //     auto nx = std::next(it, 1); // next element in the list
    //     if(*it > *nx) { return false; }
    //     if (i + 1 == nodes.size()) { break; } // means that we reached end of the list
    //     ++i;
    // }
    // return true;
}

// TC - O(N^2) - can be improved if we know MIN and MAX ranges of values:
// Add 2 parameters to the method and check if current data inside the range. On each level range will be changed: data for MAX in left and data+1 for MIN in right
// isBST(BST_Node* currentNode, T MIN_DATA, T MAX_DATA) - check if currentNode->data < MIN_DATA || currentNode->data > MAX_DATA(return false). Call same function for left and right parts and update ranges
template <class T>
bool BinarySearchTree<T>::isBST(BST_Node* currentNode, const T &data)
{
    if (currentNode == nullptr) return true;
    
    // Check that data of nodes in left side(from currentNode) is less than data in current Node
    // AND Check that data of nodes in right side(from currentNode) is more than data in current Node
    if (isBSTLess(currentNode->left, data) && isBSTMore(currentNode->right, data))
    {
        // Execute same logic for right and left nodes(in the end logic will be executed for all nodes in the tree)
        if (isBST(currentNode->left, currentNode->left->data) && isBST(currentNode->right, currentNode->right->data))
        {
            return true;
        }
    }
    return false;
}

template <class T>
bool BinarySearchTree<T>::isBSTLess(BST_Node* currentNode, const T &data)
{
    if(currentNode == nullptr) return true;
    if(currentNode->data <= data)
    {
        // Data in left and right nodes should be less then provided data(data taken from executable node)
        if( isBSTLess(currentNode->left, data) && isBSTLess(currentNode->right, data) ) return true;
    }
    return false;
}

template <class T>
bool BinarySearchTree<T>::isBSTMore(BST_Node* currentNode, const T &data)
{
    if(currentNode == nullptr) return true;
    if(currentNode->data > data)
    {
        // Data in left and right nodes should be more then provided data(data taken from executable node)
        if( isBSTMore(currentNode->left, data) && isBSTMore(currentNode->right, data) ) return true;
    }
    return false;
}

// !! The best approach: Go through tree by <call left><read data><call right> AND add data to the array(in BST array will be sorted). Loop by array checking for [i] > [i+1] - in this case false
template <class T>
void BinarySearchTree<T>::isBSTBest(BST_Node* currentNode, std::list<T> &nodes)
{
    if (currentNode == nullptr) return;
    isBSTBest(currentNode->left, nodes);
    nodes.push_back(currentNode->data);
    isBSTBest(currentNode->right, nodes);
}

template <class T>

void BinarySearchTree<T>::DeleteExactNode(const T &data)
{
    DeleteExactNode(root, data);
}

template <class T>
void BinarySearchTree<T>::DeleteExactNode(BST_Node* &currentNode, const T &data)
{
    if( currentNode == nullptr ) return;
    else if( data < currentNode->data ) DeleteExactNode(currentNode->left, data);
    else if( data > currentNode->data ) DeleteExactNode(currentNode->right, data);
    // When required Node was found
    else
    {
        // Case 1: when Node is leaf Node - just delete it
        if( currentNode->left == nullptr && currentNode->right == nullptr )
        {
            delete currentNode;
            currentNode = nullptr;
            return;
        }
        // Case 2: when only one way(left or right) - put left/right Node to current and delete old current
        else if( currentNode->left == nullptr || currentNode->right == nullptr )
        {
            BST_Node* temp = currentNode;
            // When left
            if (currentNode->left != nullptr) currentNode = currentNode->left;
            // When right
            if (currentNode->right != nullptr) currentNode = currentNode->right;
            delete temp;
            temp = nullptr;   
            return;     
        }
        // Case 3: when both ways(left and right) - find MIN right Node(or max left), update data in current, delete MIN right Node
        else if( currentNode->left != nullptr && currentNode->right != nullptr )
        {
            T minRight = GetMin(currentNode->right);
            currentNode->data = minRight;
            DeleteExactNode(currentNode->right, currentNode->data);
            return;
        }
    }
}