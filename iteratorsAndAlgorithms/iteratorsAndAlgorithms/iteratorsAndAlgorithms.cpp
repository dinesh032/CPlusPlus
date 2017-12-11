#include<iostream>
#include<string>
#include<iterator>
#include<conio.h>
#include<set>
using namespace std;

//************ 5 categories of iterators *************
//1. Random access iterators: vector, deque, array
//Eg. vector<int> itr;
//	  itr = itr + 5;	//adv by 5, points to itr[5]
//	  itr = itr - 4;
//	  if(itr2 > itr1)	can compare the iterators
//	  ++itr, --itr etc

//2. Bidirectional iterator: list, set/multiset, map/multimap
//	list<int> itr;
//	++itr, --itr the only operations available

//3. Forward iterator: forward list
//	forward_list<int> itr;
//	++itr, the only available operation

//4. Input iterator: read and process values while iterating forward.
//int x = *itr

//5. Output iterator: output values while iterating forward.
//*itr = 100

// Iterator adapters
// -A special, more powerful adapter
// 1. Insert iterator
// 2. stream iterator
// 3. reverse iterator	traverse a container in reverse order
//	reverse_iterator<vector<int>>:: iterator ritr;
//	for(ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
//		cout<<*ritr;	//prints vec in reverse order
// 4. move iterator (C++11)
int main() {

	set<int> myset = { 2, 3, 1, 6, 8 };
	//every container has a iterator & a const_iterator
	set<int>::iterator itr;
	set<int>::const_iterator citr;		//can only read
	for (citr = myset.begin(); citr != myset.end(); citr++)
		cout << *citr << ", ";	//can only print, can't modify *citr

//Iterator functions
// advance(itr, 5);		  equivalent to itr = itr + 5
// distance(itr1, itr2)	  measure distance b/w itr1 & itr2
	_getch();
	return 0;
}