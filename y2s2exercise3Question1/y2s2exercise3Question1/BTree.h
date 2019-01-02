#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <functional>
#include "BNode.h"
#include "Treatment.h"
using namespace std;

template <typename T>
class BTree//BTree with max degree M
{
	BNode<T> *root;

public:
	BTree() { root = NULL; } //build an empty tree
	~BTree() { deleteTree(); }
	void insert(T x);      //add a value to the tree
	void deleteVal(T x);
	void deleteSubTree(BNode<T> *t);
	void deleteTree() { deleteSubTree(root); }
	void printSubTree(BNode<T> *t);
	void printTree() { printSubTree(root); }
	void printAllKeys(std::function<bool(const T&)> predicate) { printAllKeys(root, predicate); }
	void printAllKeys(BNode<T> *p, std::function<bool(const T&)>);
	T* search(T x) { return search(root, x); }
	T* search(BNode<T> *p, T x);


	//------------------
//	void BTree<T>::inOrder(BNode<T> * current);
};


template <typename T>
void BTree<T>::insert(T x) //add a value to the tree
{
	BNode<T> *tmp = NULL;
	T tx;
	if (root == NULL)
		root = new BNode<T>(x);
	else
	{
		root->insert(x, tx, tmp);
		if (tmp) //a split was done;
		{
			BNode<T> *newRoot = new BNode<T>(tx);
			newRoot->Son[0] = root;
			newRoot->Son[1] = tmp;
			root = newRoot;
		}
	}

}

template <typename T>
void BTree<T>::deleteVal(T x)
{
	T tmp;
	bool holeSent;
	if (root == NULL) return;
	root->deleteVal(x, false, tmp, holeSent); //and if a hole was return, the depth of all leaves reduces in one.
	if (holeSent == true)
		if (root->nsons == 1) //the son will be the root
		{
			BNode<T> *tmp = root;
			root = root->Son[0];
			delete tmp;
		}
	//otherwise, the root is allowed to have less than M/2 nodes.
}







template <typename T>
void BTree<T>::deleteSubTree(BNode<T> *t)
{
	if (t == NULL) return;
	for (int i = 0; i < t->nsons; i++)
	{
		deleteSubTree(t->Son[i]);
	}
	delete t;

}



template <typename T>
void BTree<T>::printAllKeys(BNode<T> *p, std::function<bool(const T&)> predicate)
{

}

template <typename T>
T* BTree<T>::search(BNode<T> *p, T x)
{
	if (p != NULL) // checking the tree is not empty
	{
		for (int i = 0; i < p->nkeys; i++)
		{
			if (p->Key[i] == x)
				return &(p->Key[i]); // the key was found
			else if ((i == 0) && (x < p->Key[i]))
				return search(p->Son[i], x);
			else if (i > 0 && x<p->Key[i] && x>p->Key[i - 1])
				return search(p->Son[i], x);
			else if (i == p->nkeys - 1 && x > p->Key[i] && p->Son[i + 1] != NULL)
				return search(p->Son[i + 1], x);
		}
	}
	return NULL;
}




template <typename T>
void BTree<T>::printSubTree(BNode<T> *t)
{
	if (t == NULL) // checking if the tree is not empty
	{
		cout << "This is tree is empty";
		return;
	}
	if (t->Son[0] == NULL) // checking if this node is a leaf
	{
		for (int i = 0; i < t->nkeys; i++)
			cout << t->Key[i] << endl;
		return;
	}
	for (int i = 0; i < t->nsons; i++)
	{
		printSubTree(t->Son[i]);
		if (i != t->nsons - 1)
			cout << t->Key[i] << endl;
	}
}

//// inOrder processing of tree rooted at current
//template <class T>
//void BTree<T>::inOrder(BNode<T> * current)
//{
//	if (current)
//	{
//		inOrder(current->left);
//		process(current->value);
//		inOrder(current->right);
//	}
//}
