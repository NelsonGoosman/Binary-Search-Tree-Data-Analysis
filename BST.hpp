#pragma once
#include "Node.hpp"
#include "TransactionNode.hpp"
class BST {
public:
	BST() { pRoot = nullptr; }
	~BST();
	void insert(std::string data);
	void inOrderTraversal();
	Node* findSmallest();
	Node* findLargest();
	TransactionNode* makeNode(std::string data);
private:
	Node* pRoot;
	void inOrderTraversal(Node* node);
	void insert(Node*& insertNode, Node* root);
	void destroyTree(Node* current);
	Node* findSmallest(Node* root);
	Node* findLargest(Node* root);
};

