#include<iostream>
#include<conio.h>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//unordered sets/multisets & unordered maps/multimaps
//implemented as hash table..so the elements are not ordered
//hash table = array of linked lists. array known as buckets & linked lists as entries

//Properties of unordered containers
//1. fasted searh/insert at any place O(1)
//	 associative containers takes O(logn) & vector takes O(n), deque takes O(n)
//	 list takes O(1) (given that pointers points at right place) & O(n) to search
//2. Unordered set/multiset: element value can't be changed
//3. Unordered map/multimap: element key can't be changed

void unorderedMap() {
	unordered_map<char, string> myUnorderedMap = { {'S', "Sunday"},{'M', "Monday"} };

	//printing the unordered map
	cout << endl;
	for (unordered_map<char, string>::iterator it = myUnorderedMap.begin(); it != myUnorderedMap.end(); it++) {
		cout << (*it).first << " " << (*it).second << ", ";
	}
}
void unorderedSet() {
	unordered_set<string> myset = { "red", "blue", "green" };

	//printing the set
	for (unordered_set<string>::iterator it = myset.begin(); it != myset.end(); it++)
		cout << *it << ", ";
	unordered_set<string>::iterator it = myset.find("green");		//O(1) because hash table
	if (it != myset.end())		//returns end() if "green" not in map
		cout << endl << *it << endl;

	//Inserting values in map
	myset.insert("black");		//O(1) because hash table
	//another way of insert
	vector<string> vec = {"purple", "pink"};
	myset.insert(vec.begin(), vec.end());

	//printing again
	for (unordered_set<string>::iterator it = myset.begin(); it != myset.end(); it++)
		cout << *it << ", ";

	//Hash table specific API's
	cout << endl << "Load factor: " << myset.load_factor() << endl;	//elements to buckets ratio
	string x = "purple";
	cout << x << " is in bucket #" << myset.bucket(x) << endl;
	cout << "Total # of buckets: " << myset.bucket_count() << endl;
}

int main() {
	unorderedSet();
	unorderedMap();
	_getch();
	return 0;
}