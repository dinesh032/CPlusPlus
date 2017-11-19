#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

//Functors are objects that can be treated as though they are a function or function pointer--you could write code that looks like this
//myFunctorClass functor;
//functor(1, 2, 3);
//This code works because C++ allows you to overload operator(), the "function call" operator.
//The function call operator can take any number of arguments of any types and return anything it wishes to.

struct isOdd {
	bool operator()(int x) {
		return x % 2;
	}
};
bool isEven(int x) {
	return !(x % 2);
}
int main() {

	vector<int> vec = {1,2,3,4,5,6,7,8,9};
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << ", ";
	cout << endl<< "Number of odd elements: " << count_if(vec.begin(), vec.end(), isOdd()) << endl;
	cout << "Number of even elements: " << count_if(vec.begin(), vec.end(), isEven) << endl;

	_getch();
	return 0;
}