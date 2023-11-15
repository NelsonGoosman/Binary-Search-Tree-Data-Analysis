#pragma once
#include "Node.hpp"

class TransactionNode : public Node {
public:
	TransactionNode(std::string data);
	int getUnits() const;
	void setUnits(int newUnits);
	void printData() override;
private:
	int mUnits;
};

