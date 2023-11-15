#include "BST.hpp"

BST::~BST() {
	destroyTree(pRoot);
}

void BST::destroyTree(Node* current) { 
	if (current == nullptr) return;   

	destroyTree(current->getLeft());
	destroyTree(current->getRight());
	delete current;
	current = nullptr;
}



TransactionNode* BST::makeNode(std::string data) {
	TransactionNode* newNode = new TransactionNode(data);
	return newNode;
}

void BST::insert(std::string data) {
	Node* newNode = makeNode(data);
	insert(newNode, pRoot);
}

void BST::insert(Node*& insertNode, Node* root) {
	if (root == nullptr) {
		pRoot = insertNode;
		return;
	}
	else if (*root > *insertNode) { 
		if (root->getLeft() == nullptr) {
			root->setLeft(insertNode);
			return;
		}
		else {
			insert(insertNode, root->getLeft());
		}
	}
	else if (*root < *insertNode) {
		if (root->getRight() == nullptr) {
			root->setRight(insertNode);
			return;
		}
		else {
			insert(insertNode, root->getRight());
		}
	}

	return;
	
}

void BST::inOrderTraversal() {
	inOrderTraversal(pRoot);
}

void BST::inOrderTraversal(Node* head) {
	if (head == nullptr) return;
	inOrderTraversal(head->getLeft());
	head->printData();
	inOrderTraversal(head->getRight());
}

Node* BST::findSmallest() {
	return findSmallest(pRoot);
}
Node* BST::findLargest() {
	return findLargest(pRoot);
}

Node* BST::findSmallest(Node* root) {
	if (root->getLeft() == nullptr) return root;
	findSmallest(root->getLeft());
}
Node* BST::findLargest(Node* root) {
	if (root->getRight() == nullptr) return root;
	findSmallest(root->getRight());
}