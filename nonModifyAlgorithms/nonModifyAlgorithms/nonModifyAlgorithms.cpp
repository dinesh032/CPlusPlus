#include<iostream>
#include<conio.h>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;

int main() {
	 
	vector<int> vec = {1,2,3,4,5,6,7,8,9,6};
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";
	//1. Counting alg.
	int n = count(vec.begin(), vec.end(), 6);
	int m = count_if(vec.begin(), vec.end(), [](int x) {return x < 5; });
	cout << endl << "No. of 6's:" << n << endl << "No.s less than 5:" << m << endl;
	//2. Max element
	vector<int>::iterator itr1 = max_element(vec.begin(), vec.end());
	vector<int>::iterator itr2 = min_element(vec.begin(), vec.end());
	cout << "Biggest element:" << *itr1 << endl;
	cout << "Smallest element:" << *itr2 << endl;
	//3. search algorithms
	itr1 = find(vec.begin(), vec.end(), 8);
	itr2 = find_if(vec.begin(), vec.end(), [](int x) {return x > 7;});
	if (itr1 != vec.end())
		cout << "Element " << *itr1 << " found in vec." << endl;
	else
		cout << "Element NOT found";
	cout << endl <<"First element gretaer than 7 in vec:"<< *itr2;
	//search subrange
	vector<int> vec1 = { 4,5,6,7 };
	itr1 = search(vec.begin(), vec.end(), vec1.begin(), vec1.end());	//search() finds first subrange, find_end() finds last subrange
	if (itr1 != vec.end())
		cout << endl << "subrange present, starting from:" << *itr1;
	else
		cout << endl << "subrange NOT present";
	//attribute checking algorithms..is_sorted, is_heap, is_partitioned etc
	//all_of, any_of, none_of
	if (all_of(vec.begin(), vec.end(), [](int x) {return x > 0; }))
		cout << endl << "All elements are +ve" << endl;
	else
		cout << endl << "All elements NOT +ve";

	_getch();
	return 0;
}