#pragma once
#include "header.hpp"

class Node {
public:
	Node() : pLeft(nullptr), pRight(nullptr){}
	Node(std::string data) {
		mData = data;
		pLeft = pRight = nullptr;
	}
	~Node() {
		pLeft = pRight = nullptr;
		//if (pLeft) delete pLeft;
		//if (pRight) delete pRight;
		
	}
	virtual void printData() = 0;
	std::string getData() const;
	Node*& getLeft();
	Node*& getRight();
	void setLeft(Node* newLeft);
	void setRight(Node* newRight);
	void setData(std::string newData);
protected:
	std::string mData;
	Node* pLeft;
	Node* pRight;
};

bool operator >(const Node& lhs, const Node& rhs);
bool operator <(const Node& lhs, const Node& rhs);




