#include "TransactionNode.hpp"
#include "header.hpp"

TransactionNode::TransactionNode(std::string data) {
	this->mData = data;
	std::string token;

	std::stringstream ss(data);
	getline(ss, token, ',');
	mUnits = stoi(token);
}

int TransactionNode::getUnits() const{
	return mUnits;
}
void TransactionNode::setUnits(int newUnits){
	mUnits = newUnits;
}
void TransactionNode::printData(){
	std::stringstream ss(mData);
	std::string token;
	getline(ss, token, ',');
	cout << token << " Units of ";
	getline(ss, token, ',');
	cout << token << std::endl;
}