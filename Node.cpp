#include "Node.hpp"

/*
Name: getData
Description: getter function for data 
Parameters: 
Returns: string
*/
std::string Node::getData() const {
	return mData;
}

/*
Name: getLeft
Description: returns left child pointer
Parameters: 
Returns: Node*&
*/
Node*& Node::getLeft() {
	return pLeft;
}

/*
Name: getRight
Description: getter for right child pointer
Parameters: 
Returns: Node*& 
*/
Node*& Node::getRight() {
	return pRight;
}

/*
Name: setLeft
Description: Left pointer setter 
Parameters: Node* 
Returns: void
*/
void Node::setLeft(Node* newLeft) {
	pLeft = newLeft;
}

/*
Name: setRight
Description: right pointer setter
Parameters: Node*
Returns: void
*/
void Node::setRight(Node* newRight) {
	pRight = newRight;
}

/*
Name: setData
Description: data setter fucntion
Parameters: string
Returns:void
*/
void Node::setData(std::string newData) {
	mData = newData;
}

bool operator >(const Node& lhs, const Node& rhs) {
	std::string lhsVal, rhsVal;
	int i = 0;
	while (lhs.getData()[i] != ',') {
		lhsVal += lhs.getData()[i];
		i++;
	}
	i = 0;
	while (rhs.getData()[i] != ',') {
		rhsVal += rhs.getData()[i];
		i++;
	}
	return stoi(lhsVal) > stoi(rhsVal);
}

bool operator <(const Node& lhs, const Node& rhs) {
	return rhs > lhs;
}

