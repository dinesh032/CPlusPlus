#include<iostream>
#include<vector>
#include<iterator>
#include<conio.h>
#include<deque>
#include<list>
#include<forward_list>
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

//deque is double ended vector. Can insert/delete from both ends
	deque<int> deq = { 4,5,7 };
	deq.push_front(3);
	deq.push_back(9);
	cout << endl << "Deque:";
	for (deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
		cout << *it << ", ";

	cout << endl << "Vector:";
	cout << vec[2] << " " << vec.at(2) << endl;	//both are same i.e will print the 2nd index element
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	//using iterator for traversing
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
		cout << *itr << " ";

//list is double ended list container. 
//Fast insert/remove: O(1)
//Linear search: O(n). same as vector/deque but in practice still slower because of memory locality problem in lists
//No random access like vector/deque.
	list<int> list1 = { 3, 7, 12};
	list<int> list2 = { 8, 9, 10 };
	list1.push_front(2);
	//inserting randomly
	list<int>::iterator it = find(list1.begin(), list1.end(), 7);
	list1.insert(it, 5);

	//splice functionality..adding list2 to list1 & printing list1
	it++;
	list1.splice(it, list2, list2.begin(), list2.end());
	cout << endl << "List:";
	for (list<int>::iterator it = list1.begin(); it != list1.end(); it++)
		cout << *it << " ";

//forward_list is single linked list
	forward_list<int> l1 = {1,3,5,6,9};

	_getch();
	return 0;
}