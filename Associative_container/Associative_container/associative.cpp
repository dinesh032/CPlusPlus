#include<iostream>
#include<set>
#include<map>
#include<conio.h>

using namespace std;

//Associative containers: set, multiset, map, multimap. Implemented as a binary tree.

void setFunc() {
	//set contains NO duplicates
	set<int> myset;
	myset.insert(3);		//myset = {3}
	myset.insert(1);		//myset = {1, 3}
	myset.insert(7);		//myset = {1, 3, 7}		insertion takes O(logn)

	set<int>::iterator it;
	it = myset.find(7);		//find() takes O(logn). Sequence containers except list take O(n)
	
	pair<set<int>::iterator, bool> ret;		//pair<itr, bool> is returned for every insert function
	ret = myset.insert(7);					//in this case bool is false because 7 is already there in set
	if (ret.second == false)				//so, point the iterator to 7 in the set
		it = ret.first;

	//printing the list
	cout << "Set elements: ";
	for (set<int>::iterator it = myset.begin(); it != myset.end(); it++)
		cout << *it << " ";
}

void multiSetFunc() {
	//same as sets but contains duplicate elements
	multiset<int> myset;
}

void mapFunc() {
	//key/value pairs..maps doesNOT allow duplicate keys whereas multimap allows duplicates
	map<char, int> mymap;
	mymap.insert(pair<char, int>('a', 100));
	//another way of insert
	mymap.insert(make_pair('z', 200));

	mymap.find('z');		//O(logn)
	//printing the map
	cout << endl << "Map elements: ";
	for (map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
		cout << (*it).first << " "<<(*it).second<<", ";
}
int main() {

	//associative container is binary tree implementation i.e always sorted
	setFunc();
	multiSetFunc();

	mapFunc();
	_getch();
	return 0;
}