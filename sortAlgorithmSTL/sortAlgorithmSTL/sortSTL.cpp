#include<iostream>
#include<vector>
#include<conio.h>
#include<algorithm>
#include<iterator>
using namespace std;
int main() {
	vector<int> vec = {6,12,8,56,18,145,2,78};
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr<<" ";
	stable_partition(vec.begin(), vec.end(), [](int x) {return x < 20; });	//partition into 2 subarrays..one with <20 & >20
	cout << endl;
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	sort(vec.begin(), vec.end());	//sort function
	cout << endl;
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr <<" ";
//Heap algorithms..make_heap() creates a heap & sort_heap() sorts the heap
	make_heap(vec.begin(), vec.end());
	cout << endl;
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	sort_heap(vec.begin(), vec.end());
	cout << endl;
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
//sorted data algorithms..alg's that require data to be sorted
//binary search, merge, set operations
	bool check = binary_search(vec.begin(), vec.end(), 78);
	if (check)
		cout << endl << "78 element present";
	else
		cout << endl << "78 element NOT present";
	vector<int> vec1 = {1,2,4};
	vector<int> vec2 = {2,4,6,7};
	vector<int> vec3 = {0,0,0,0,0,0,0};
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin()); //vec3 = {1,2,2,4,4,6,7}
	cout << endl;
	for (vector<int>::iterator itr = vec3.begin(); itr != vec3.end(); ++itr)
		cout << *itr << " ";
	set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());	//vec3 = {1,2,4,6,7}
	cout << endl;
	for (vector<int>::iterator itr = vec3.begin(); itr != vec3.end(); ++itr)
		cout << *itr << " ";
	set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());		//vec3 = {2,4}
	cout << endl;
	for (vector<int>::iterator itr = vec3.begin(); itr != vec3.end(); ++itr)
		cout << *itr << " ";
	_getch();
	return 0;
}