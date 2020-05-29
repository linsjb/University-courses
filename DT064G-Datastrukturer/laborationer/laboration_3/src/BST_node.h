#pragma once
#include <algorithm>
#include <iostream>

struct BST_node {
	int data;
	BST_node* left;
	BST_node* right;
};
//
// Function to create a new Node in heap
BST_node* new_node(int key) {
	BST_node* new_node = new BST_node();
	new_node->data = key;
	new_node->left = nullptr;
	new_node->right = nullptr;
	return new_node;
}
//
// To insert data in BST, returns address of root node
BST_node* insert_BSTnode(BST_node* node, int key) {
	// empty tree
	if (node == NULL) {
		return new_node(key);
	}

	// if data to be inserted is lesser, insert in left subtree.
	if (key < node->data) {
		node->left = insert_BSTnode(node->left, key);
	}

	// else, insert in right subtree.
	else if(key > node->data) {
		node->right = insert_BSTnode(node->right, key);
	}

	return node;
}
//
//To search an element in BST, returns true if element is found
bool search_BSTnode(BST_node* root, int data) {
	if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		return true;
	}
	else if (data <= root->data) {
		return search_BSTnode(root->left, data);
	} else {
		return search_BSTnode(root->right, data);
	}
}
