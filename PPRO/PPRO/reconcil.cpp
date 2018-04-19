#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;
float pproMatch = 0, pproMatchCount = 0;		//variables for ppro count(unknown transactions) and match volumes

/*Reconciliation method for HarderPay.csv file */
void 
reconciliationHarderPay(ifstream &ppro, ifstream &harderpay) {
	string transactionId1, transactionId2;
	string merchantTransactionId1, merchantTransactionId2;
	string state1, state2;
	string amount1, amount2;
	float total = 0, match = 0;
	int totalCount = 0, matchCount = 0;
	if (!harderpay.is_open())
		cout << "ERROR: File Open" << endl;
	getline(ppro, transactionId1, '\n');
	getline(harderpay, transactionId2, '\n');
	/*Getting each HarderPay entry and comparing it with all prpoPay entries*/
	while (harderpay.good()) {
		getline(harderpay, transactionId2, ',');
		getline(harderpay, merchantTransactionId2, ',');
		getline(harderpay, state2, ',');
		getline(harderpay, amount2, '\n');
		total = total + stof(amount2);
		totalCount++;
		if (!ppro.is_open())
			cout << "ERROR: File Open" << endl;
		while (ppro.good()) {
			getline(ppro, transactionId1, ',');
			getline(ppro, merchantTransactionId1, ',');
			getline(ppro, state1, ',');
			getline(ppro, amount1, '\n');
			if (transactionId1 == transactionId2 && merchantTransactionId1 == merchantTransactionId2
				&& state1 == state2) {
				match = match + stof(amount2);
				matchCount++;
			}
		}
		ppro.clear();
		ppro.seekg(0, ios::beg);
	}
	pproMatch = pproMatch + match;
	pproMatchCount = pproMatchCount + matchCount;
	cout << "transactions-harderpay.csv" << endl;
	if (totalCount - matchCount != 0)
		cout << "This file has " << (totalCount - matchCount) << " unknown transactions." << endl;
	cout << "Total volume: " << total << endl;
	cout << "Matched volume: " << match << endl;
	cout << "Missing volume: " << total - match << endl;
}
/*Reconciliation method for simplePay.csv file */
void reconciliationSimplePay(ifstream &ppro, ifstream &simplepay) {
	string transactionId1, transactionId2;
	string merchantTransactionId1, merchantTransactionId2;
	string state1, state2;
	string amount1, amount2;
	float total = 0, match = 0;
	int totalCount = 0, matchCount = 0;
	if(!simplepay.is_open())
		cout << "ERROR: File Open" << endl;
	getline(ppro, transactionId1, '\n');
	getline(simplepay, transactionId2, '\n');
	/*Getting each simplePay entry and comparing it with all prpoPay entries*/
	while (simplepay.good()) {
		getline(simplepay, transactionId2, ',');
		getline(simplepay, merchantTransactionId2, ',');
		getline(simplepay, state2, ',');
		getline(simplepay, amount2, '\n');
		if(transactionId2 == "")
			break;
		total = total + stof(amount2);
		totalCount++;
		if (!ppro.is_open())
			cout << "ERROR: File Open" << endl;
		while (ppro.good()) {
			getline(ppro, transactionId1, ',');
			getline(ppro, merchantTransactionId1, ',');
			getline(ppro, state1, ',');
			getline(ppro, amount1, '\n');
			if (transactionId1 == transactionId2 && state1 == state2) {
				match = match + stof(amount2);
				matchCount++;
			}
		}
		ppro.clear();
		ppro.seekg(0, ios::beg);
	}
	pproMatch = pproMatch + match;
	pproMatchCount = pproMatchCount + matchCount;
	cout << endl << "transactions-simplepay.csv" << endl;
	if (totalCount - matchCount != 0)
		cout << "This file has " << (totalCount - matchCount) << " unknown transactions." << endl;
	cout << "Total volume: " << total << endl;
	cout << "Matched volume: " << match << endl;
	cout << "Missing volume: " << total - match << endl;
}
/*Reconciliation method for simplerPay.csv file */
void 
reconciliationSimplerPay(ifstream &ppro, ifstream &simplerpay) {
	string transactionId1, transactionId2;
	string merchantTransactionId1, merchantTransactionId2;
	string state1, state2;
	string amount1, amount2;
	float total = 0, match = 0;
	int totalCount = 0, matchCount = 0;
	if (!simplerpay.is_open())
		cout << "ERROR: File Open" << endl;
	getline(ppro, transactionId1, '\n');
	getline(simplerpay, transactionId2, '\n');
	/*Getting each simplerPay entry and comparing it with all prpoPay entries*/
	while (simplerpay.good()) {
		getline(simplerpay, merchantTransactionId2, ',');
		getline(simplerpay, state2, ',');
		getline(simplerpay, amount2, '\n');
		if (merchantTransactionId2 == "")
			break;
		total = total + stof(amount2);
		totalCount++;
		if (!ppro.is_open())
			cout << "ERROR: File Open" << endl;
		while (ppro.good()) {
			getline(ppro, transactionId1, ',');
			getline(ppro, merchantTransactionId1, ',');
			getline(ppro, state1, ',');
			getline(ppro, amount1, '\n');
			if (merchantTransactionId1 == merchantTransactionId2 && state1 == state2) {
				match = match + stof(amount2);
				matchCount++;
			}
		}
		ppro.clear();
		ppro.seekg(0, ios::beg);
	}
	pproMatch = pproMatch + match;
	pproMatchCount = pproMatchCount + matchCount;
	cout << endl << "transactions-simplerpay.csv" << endl;
	if(totalCount-matchCount != 0)
		cout << "This file has " << (totalCount - matchCount) << " unknown transactions." << endl;
	cout << "Total volume: " << total << endl;
	cout << "Matched volume: " << match << endl;
	cout << "Missing volume: " << total - match << endl;
}
/*Reconciliation method for ppro.csv file */
void 
reconciliationPpro(ifstream &ppro) {
	string transactionId;
	string merchantTransactionId;
	string state;
	string amount;
	float total = 0;
	int totalCount = 0;
	if (!ppro.is_open())
		cout << "ERROR: File Open" << endl;
	getline(ppro, transactionId, '\n');
	while (ppro.good()) {
		getline(ppro, transactionId, ',');
		getline(ppro, merchantTransactionId, ',');
		getline(ppro, state, ',');
		getline(ppro, amount, '\n');
		total = total + stof(amount);
		totalCount++;
	}
	cout << endl << "transactions-ppro.csv" << endl;
	if (totalCount - pproMatchCount != 0)
		cout << "This file has " << (totalCount - pproMatchCount) << " unknown transactions." << endl;
	cout << "Total volume: " << total << endl;
	cout << "Matched volume: " << pproMatch << endl;
	cout << "Missing volume: " << total - pproMatch << endl;
}

int 
main() {
	/*Getting file handles for the .csv files*/
	ifstream ppro("transactions-ppro.csv");
	ifstream harderpay("transactions-harderpay.csv");
	ifstream simplepay("transactions-simplepay.csv");
	ifstream simplerpay("transactions-simplerpay.csv");

	/*Calling respective reconciliation functions*/
	reconciliationHarderPay(ppro, harderpay);
	reconciliationSimplePay(ppro, simplepay);
	reconciliationSimplerPay(ppro, simplerpay);
	reconciliationPpro(ppro);
	
	cin.get();
	return 0;
}