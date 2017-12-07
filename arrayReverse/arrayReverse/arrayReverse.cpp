#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

void printVector(vector<int>& vec) {
	cout << endl;
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << " ";
}
void reverseVector(vector<int>& vec, int start, int end) {
	while (start < end) {
		swap(vec[start], vec[end]);
		start++;
		end--;
	}
}
int main() {
	vector<int> vec = {1,2,3,4,5,6,7};
	printVector(vec);

	reverseVector(vec, 0, vec.size()-1);

	printVector(vec);
	_getch();
	return 0;
}