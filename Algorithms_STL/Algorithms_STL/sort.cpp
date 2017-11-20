#include<iostream>
#include<algorithm>
#include<vector>
#include<conio.h>

using namespace std;

void print(vector<int>& vec) {

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << " ";
}
int main() {

	int n = 7;
	vector<int> vec = { 3,1,7,5,4,9,12 };

	//finding out the min element
	vector<int>::iterator itr = min_element(vec.begin(), vec.end());
	cout << endl << "Vector before sort: ";
	print(vec);
	cout << endl << "Smallest element is: " << *itr;

	//sorting the vector
	sort(vec.begin(), vec.end());
	cout << endl << "Vector after sort: ";
	print(vec);
	
	//reversing the vector
	reverse(vec.begin(), vec.end());
	cout << endl << "Vector after reversing: ";
	print(vec);

	_getch();
	return 0;
}