#include<iostream>
#include<conio.h>
#include<vector>
#include<set>
using namespace std;

void firstRepeatingElement(vector<int>& vec, int n) {
	set<int> myset;
	int min = -1;
	for (int i = n - 1; i >= 0; i--) {

		if (myset.find(vec[i]) != myset.end())
			min = i;
		else
			myset.insert(vec[i]);
	}
	if (min == -1)
		cout << endl << "No repeating elements";
	else
		cout << endl << "First repeating element: " << vec[min];
}
int main() {
	vector<int> vec = {1,2,3,2,4,5,6};
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << ", ";
	}
	firstRepeatingElement(vec, vec.size());
	_getch();
	return 0;
}