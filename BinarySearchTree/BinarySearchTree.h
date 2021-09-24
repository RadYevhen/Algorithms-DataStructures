#pragma once
#include <iostream>
#include <queue>
#include <list>
#include <algorithm> // std::is_sorted

template <class T>
class BinarySearchTree
{
    private:
        struct BST_Node
        {
            T data;
            BST_Node* left;
            BST_Node* right;
        };

        BST_Node* root;

        BST_Node* CreateEmptyBSTNode(const T data);
        BST_Node* Insert(BST_Node* currentNode, const T data);
        bool Search(const BST_Node* currentNode, const T data);
        void Print(const BST_Node* currentNode);
        T GetMin(const BST_Node* currentNode);
        T GetMax(const BST_Node* currentNode);
        int GetTreeHeight(const BST_Node* currentNode);
        void Delete(BST_Node* &currentNode);
        void Delete(BST_Node* &currentNode, const T &data, bool isForDelete);
        bool isBST(BST_Node* currentNode, const T &data);
        bool isBSTLess(BST_Node* currentNode, const T &data);
        bool isBSTMore(BST_Node* currentNode, const T &data);
        void isBSTBest(BST_Node* currentNode, std::list<T> &nodes);
        void DeleteExactNode(BST_Node* &currentNode, const T &data);

    public:
        BinarySearchTree();
        BinarySearchTree(const T data);
        ~BinarySearchTree();
        bool Search(const T data);
        void Insert(const T data);
        void Delete(const T data);
        T GetMin();
        T GetMax();
        int GetTreeHeight();
        void Print();
        void PrintByLevel();
        bool isBST();
        void DeleteExactNode(const T &data);
};