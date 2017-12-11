#include<iostream>
#include<list>
#include<conio.h>

using namespace std;

int main() {


	//List container
	//basically, a doubly linked list
	//Can insert an element in constant time..find() function helps in this
	//no random access like in vector i.e no []operator

	//one more very important function that list posses is splice
	//mylist1.splice(itr, mylist2, itr_a, itr_b); takes O(1)

	//Forward list
	//basically a singly linked list

	list<int> mylist = {2, 4, 7};
	mylist.push_back(9);
	mylist.push_front(1);		//mylist = {1, 2, 4, 7, 9}

	list<int>::iterator itr = find(mylist.begin(), mylist.end(), 4);		//itr=4, find() function is very effective for insert
	mylist.insert(itr, 3);		//Insert is fast O(1)

	for (list<int>::iterator itr = mylist.begin(); itr != mylist.end(); itr++)
		cout << *itr << " ";

	_getch();
	return 0;
}