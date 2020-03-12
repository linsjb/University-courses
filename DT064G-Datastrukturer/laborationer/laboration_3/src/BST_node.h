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
BST_node* get_new_BSTnode(BST_node node) {
	BST_node* new_node = new BST_node();
	new_node->data = node.data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
//
// To insert data in BST, returns address of root node
BST_node* insert_BSTnode(BST_node* root, BST_node new_node) {

	// empty tree
	if (root == NULL) {
		// std::cout << "inserted" << new_node.data << std::endl; //NOTE Visar insättningar
		root = get_new_BSTnode(new_node);
	}

	// if data to be inserted is lesser, insert in left subtree.
	else if (new_node.data <= root->data) {
		//std::cout << "left pass " << std::endl;
		//node_container.erase(node_container.begin());
		root->left = insert_BSTnode(root->left, new_node);
	}

	// else, insert in right subtree.
	else {
		//std::cout << "right pass " << std::endl;
		//node_container.erase(node_container.begin());
		root->right = insert_BSTnode(root->right, new_node);
	}

	return root;
}
//
//To search an element in BST, returns true if element is found
bool search_BSTnode(BST_node* root, int data) {
	if (root == NULL) {
		// std::cout << data << " does not exist" << "\n"; // NOTE print control
		return false;
	}
	else if (root->data == data) {
		// std::cout << data << " exist" << "\n"; // NOTE print control
		return true;
	}
	else if (data <= root->data) {
		return search_BSTnode(root->left, data);
	} else {
		return search_BSTnode(root->right, data);
	}
}
