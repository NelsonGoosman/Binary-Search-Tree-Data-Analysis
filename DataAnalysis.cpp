#include "DataAnalysis.hpp"

DataAnalysis::DataAnalysis() {
	openFile();
}
DataAnalysis::~DataAnalysis() {
	if (csvStream.is_open()) csvStream.close();
}

void DataAnalysis::openFile() {
	csvStream.open("data.csv");
	if (!csvStream.is_open()) {
		cout << "Error opening file";
	}
}

std::istream& DataAnalysis::readLine(int& units, std::string& type, std::string& transaction, std::string& data) {
	std::string line, token;
	std::istream& result = getline(csvStream, line);
	data = line;
	if (result) {
		std::stringstream ss(line);
		getline(ss, token, ',');
		units = stoi(token);
		getline(ss, token, ',');
		type = token;
		getline(ss, token, ',');
		transaction = token;
	}
	
	return result;
}

int DataAnalysis::transactionType(std::string& transaction) {
	return (transaction == "Sold") ? Transaction::SOLD : Transaction::PURCHASED;
}

void DataAnalysis::readData() {
	int units;
	std::string type, transaction, data;
	while (readLine(units, type, transaction, data)) {
		if (transactionType(transaction) == Transaction::SOLD) {
			//makenode and insert into sold bst
			mTreeSold.insert(data);
		}
		else {
			//insert into purachsed bst

			mTreePurchased.insert(data);

		}
	}
	csvStream.close();
}


void DataAnalysis::analyzeTrends() {
	Node* mostPurchased, * leastPurchased,
		* mostSold, * leastSold;
	mostPurchased = mTreePurchased.findLargest();
	leastPurchased = mTreePurchased.findSmallest();
	mostSold = mTreeSold.findLargest();
	leastSold = mTreeSold.findSmallest();
	cout << "Most Purchased Item: ";
	mostPurchased->printData();
	cout << "Least Purchased Item: ";
	leastPurchased->printData();
	cout << "Most Sold Item: ";
	mostSold->printData();
	cout << "Least Sold Item: ";
	leastSold->printData();
	cout << "\nAll Sales:\n";
	mTreeSold.inOrderTraversal();
	cout << "\nAll Purchases:\n";
	mTreePurchased.inOrderTraversal();
}

void DataAnalysis::runAnalysis() {
	readData();
	analyzeTrends();
}


