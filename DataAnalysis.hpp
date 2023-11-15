#pragma once
#include "BST.hpp"

class DataAnalysis {
public:
	DataAnalysis();
	~DataAnalysis();
	void runAnalysis();
private:
	BST mTreeSold, mTreePurchased;
	std::ifstream csvStream;
	void openFile();
	std::istream& readLine(int& units, std::string& type, std::string& transaction, std::string& data);
	void readData();
	int transactionType(std::string& transaction);
	void analyzeTrends();
	enum Transaction {PURCHASED, SOLD};
};