#include<iostream>
#include<vector>
#include<iterator>
#include<conio.h>

using namespace std;

int main() {

// Vectors are dynamically allocated contiguous array in memory
//Properties of vector
//1. fast insert/remove at the end O(1)
//2. slow insert/remove at the begining or in the middle O(n)
//3. slow search O(n) 
	vector<int> vec;	//vec.size = 0 now
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(7);	//vec.size is 3 now

	cout << vec[2] << " " << vec.at(2) << endl;	//both are same i.e will print the 2nd index element

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	//using iterator for traversing
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
		cout << *itr << " ";
	_getch();
	return 0;
}