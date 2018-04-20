#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
//value changing algorithms.
//Eg, copy, move, transform, swap, fill, replace, remove
int main() {
	vector<int> vec1 = {1,2,3,4,5,6,7};
	vector<int> vec2 = {0,0,0,0,0,0,0,0,0,0,0};
	vector<int>::iterator itr1, itr2;
	pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr;
	//copy function
	copy(vec1.begin(), vec1.end(), vec2.begin());
	for (itr1 = vec2.begin(); itr1 != vec2.end(); ++itr1)
		cout << *itr1 << " ";
	cout << endl;
	copy_if(vec1.begin(), vec1.end(), vec2.begin(), [](int x) {return x > 3; });
	for (itr1 = vec2.begin(); itr1 != vec2.end(); ++itr1)
		cout << *itr1 << " ";

	//move() function..cut & paste..moves the data to another container
	move(vec1.begin(), vec1.end(), vec2.begin());
	cout << endl;
	for (itr1 = vec2.begin(); itr1 != vec2.end(); ++itr1)
		cout << *itr1 << " ";

	//transform function..perform an operation on vector & store in another vector
	transform(vec1.begin(), vec1.end(), vec2.begin(), [](int x) {return x - 1; });
	cout << endl;
	for (itr1 = vec2.begin(); itr1 != vec2.end(); ++itr1)
		cout << *itr1 << " ";

	//fill() & generate() function
	fill(vec2.begin(), vec2.end(), 4);
	cout << endl;
	for (itr1 = vec2.begin(); itr1 != vec2.end(); ++itr1)
		cout << *itr1 << " ";
	generate(vec2.begin(), vec2.end(), rand);
	cout << endl;
	for (itr1 = vec2.begin(); itr1 != vec2.end(); ++itr1)
		cout << *itr1 << " ";
	//replace() function
	replace(vec1.begin(), vec1.end(), 6, 12);
	cout << endl;
	for (itr1 = vec1.begin(); itr1 != vec1.end(); ++itr1)
		cout << *itr1 << " ";
//Order changing algorithms-- reverse, rotate, permute, shuffle..they change the order, not necessarily the element value
	reverse(vec1.begin(), vec1.end());
	cout << endl;
	for (itr1 = vec1.begin(); itr1 != vec1.end(); ++itr1)
		cout << *itr1 << " ";
	rotate(vec1.begin(), vec1.begin() + 3, vec1.end());
	cout << endl;
	for (itr1 = vec1.begin(); itr1 != vec1.end(); ++itr1)
		cout << *itr1 << " ";
	_getch();
	return 0;
}