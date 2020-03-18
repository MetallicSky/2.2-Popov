#pragma once

#include <iostream>
#include <Windows.h>

#define RED 0
#define BLACK 1

#define underlineON "\033[4m"
#define underlineOFF "\033[0m"


using namespace std;

template <typename T>
class RBTree
{
public:
	RBTree();

	void insert(T data);
	void Print();
	void remove(T data);

private:

	template<typename T>
	class Node
	{
	public:
		Node* parent;
		Node* left;
		Node* right;
		bool color;
		T data;

		Node(T data = T(), Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr, bool color = RED)
		{
			this->data = data;
			this->parent = parent;
			this->left = left;
			this->right = right;
			this->color = color;
		}
	};


	void Print(int index, int spaces, Node<T> *q);

	void insert(Node<T> *parent, T data);
	void uncleCheck(Node<T> *node);

	void remove(Node<T> *node);

	Node<T>* root;
	Node<T>* leaf;
	unsigned int size;
};

template<typename T>
RBTree<T>::RBTree()
{
	size = 0;
	root = nullptr;
	leaf = new Node<T>(NULL, nullptr, nullptr, nullptr, BLACK);
}



template<typename T>
void RBTree<T>::insert(T data)
{
	if (size == 0)
	{
		root = new Node<T>(data, nullptr, leaf, leaf, BLACK);
		size++;
		return;
	}
	insert(root, data);
}



template<typename T>
void RBTree<T>::Print()
{
	int index = 0;
	int spaces = 0;

	if (index < size)
	{
		if (root->right != nullptr)
			Print(index, spaces + 4, root->right);
		for (int i = 0; i < spaces; i++)
			cout << ' ';
		if (root->color == BLACK)
		{
			cout << underlineON << root->data;
			cout << underlineOFF << endl;
		}
		else
			cout << root->data << endl;
		if (root->left != nullptr)
			Print(index, spaces + 4, root->left);
		index++;
	}
}

template<typename T>
void RBTree<T>::remove(T data)
{
	Node<T>* node = root;
	while (node != leaf)
	{
		if (node->data == data)
		{
			remove(node);
			node = root;
		}
		else if (node->data > data)
			node = node->left;
		else
			node = node->right;
	}
}



template<typename T>
void RBTree<T>::Print(int index, int spaces, Node<T> *q)
{
	if (index < size)
	{
		if (q->right != nullptr)
			Print(index, spaces + 4, q->right);
		for (int i = 0; i < spaces; i++)
			cout << ' ';
		if (q->color == BLACK)
		{
			cout << underlineON;
			if (q == leaf)
				cout << "NIL";
			else
				cout << q->data;
			cout << underlineOFF << endl;
		}
		else
			cout << q->data << endl;

		if (q->left != nullptr)
			Print(index, spaces + 4, q->left);
		if (q != leaf)
			index++;
	}
}

template<typename T>
void RBTree<T>::insert(Node<T> *parent, T data)
{
	if (data <= parent->data)
	{
		if (parent->left != leaf)
			insert(parent->left, data);
		else
		{
			parent->left = new Node<T>(data, parent, leaf, leaf);
			size++;
			if (parent->color == RED) // parent is red 
				uncleCheck(parent->left);
		}
	}
	else
	{
		if (parent->right != leaf)
			insert(parent->right, data);
		else
		{
			parent->right = new Node<T>(data, parent, leaf, leaf);
			size++;
			if (parent->color == RED) // parent is red
				uncleCheck(parent->right);
		}
	}
}


template<typename T>
void RBTree<T>::uncleCheck(Node<T> *node)
{
	Node<T>* parent = node->parent;
	Node<T>* grandparent = parent->parent;

	if (grandparent->left == parent) // uncle is right
	{
		Node<T>* uncle = grandparent->right;

		if (uncle->color == RED) // uncle is right red
		{
			parent->color = BLACK;
			uncle->color = BLACK;
			if (grandparent == root)
				return;
			grandparent->color = RED;
			if (grandparent->parent->color == RED) // grand-grandparent is red, so we check his uncle now
				uncleCheck(grandparent);
		}
		else // uncle is right black
		{


			if (parent->right == node) // " < " scenario, additional rotation needed
			{
				parent->right = node->left;
				parent->right->parent = parent;
				parent->parent = node;
				node->parent = grandparent;
				node->left = parent;
				grandparent->left = node;
				// now there is a " / " instead of " < "

				// finally, we swap node and parent links for further " / " rotation (because they both were swapped before)
				node = parent;
				parent = parent->parent;
			}


			grandparent->left = parent->right;
			if (grandparent->left != leaf)
				grandparent->left->parent = grandparent;
			grandparent->left->parent = grandparent;
			parent->right = grandparent;

			parent->parent = grandparent->parent;

			if (grandparent != root) // grand-grandparent exists
			{
				if (grandparent->parent->left == grandparent) // grandparent is left
					grandparent->parent->left = parent;
				else // grandparent is right
					grandparent->parent->right == parent;
			}
			else // grand-grandparent don't exist => grandparent is a root => parent is root now
				root = parent;

			grandparent->parent = parent;

			parent->color = BLACK;
			grandparent->color = RED;


		}
	}
	else // uncle is left
	{


		Node<T>* uncle = grandparent->left;

		if (uncle->color == RED) // uncle is left red
		{
			parent->color = BLACK;
			uncle->color = BLACK;
			if (grandparent == root)
				return;
			grandparent->color = RED;
			if (grandparent->parent->color == RED) // grand-grandparent is red, so we check his uncle now
				uncleCheck(grandparent);
		}
		else // uncle is left black
		{
			if (parent->left == node) // " > " scenario, additional rotation needed
			{
				parent->left = node->right;
				parent->left->parent = parent;
				parent->parent = node;
				node->parent = grandparent;
				node->right = parent;
				grandparent->right = node;
				// now there is a " \ " instead of " > "

				node = parent;
				parent = parent->parent;
			}

			Node<T>* sibling = parent->left;

			grandparent->right = parent->left;
			if (grandparent->right != leaf)
				grandparent->right->parent = grandparent;
			parent->left = grandparent;

			parent->parent = grandparent->parent;

			if (grandparent != root) // grand-grandparent exists
			{
				if (grandparent->parent->right == grandparent) // grandparent is right
				{
					grandparent->parent->right = parent;
				}
				else // grandparent is left
					grandparent->parent->left == parent;
			}
			else // grand-grandparent don't exist => grandparent is a root => parent is root now
				root = parent;

			grandparent->parent = parent;

			parent->color = BLACK;
			grandparent->color = RED;


		}
	}
}

template<typename T>
void RBTree<T>::remove(Node<T>* node)
{




	bool nodeColor = node->color;
	Node<T>* leftChild = node->left;
	Node<T>* rightChild = node->right;

	if (node->left == node->right == leaf) // case 1: node doesn't have any non-leaf kids
	{
		if (node == root) // node is root
			root = nullptr;
		else if (node->parent->left == node) // node is left
			node->parent->left = leaf;
		else // node is right
			node->parent->right = leaf;
		delete node;
		size--;
	}
	else if ((node->left != leaf) && (node->right == leaf)) // case 2.1: one child (left) isn't a leaf 
	{
		if (node == root) // node is root
		{
			root = node->left;
			node->left->parent = nullptr;
			node->left->color = BLACK;
		}
		else if (node->parent->left == node) // node is left
		{
			node->parent->left = node->left;
			node->left->parent = node->parent;
		}
		else // node is right
		{
			node->parent->right = node->left;
			node->left->parent = node->parent;
		}
		delete node;
		size--;
	}
	else if ((node->right != leaf) && (node->left == leaf)) // case 2.2: one child (right) isn't a leaf
	{
		if (node == root) // node is root
		{
			root = node->right;
			node->right->parent = nullptr;
			node->right->color = BLACK;
		}
		else if (node->parent->left == node) // node is left
		{
			node->parent->left = node->right;
			node->right->parent = node->parent;
		}
		else // node is right
		{
			node->parent->right = node->right;
			node->right->parent = node->parent;
		}
		delete node;
		size--;
	}
	else // case 3: both childs aren't leafs
	{
		Node<T>* current = node->right;
		while (current->left != leaf)
			current = current->left;
		node->data = current->data;
		remove(current);
		return;
	}

	if (nodeColor == RED || size == 0) // red node deletion doesn't require further changes || no need to balance further with 0 nodes
		return;
	
}
