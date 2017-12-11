#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<iterator>
#include<vector>

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

	vector<int> vec = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << ", ";
	cout << endl<< "Number of odd elements: " << count_if(vec.begin(), vec.end(), isOdd()) << endl;	//functor call for all elements of vector
	cout << "Number of even elements: " << count_if(vec.begin(), vec.end(), isEven) << endl;		//function call for all elements of vector

	//using lambda functions..used in place of functor call..since functor definition is small,
	//the code can defined there itself using lambda expression.
	//In summary, lambda expressions are a shortcut for creating functor objects
	//- the syntax is[capture local variables](input parameters) -> return type{ function body; }
	//-if you to use local variables you must capture them
	//- you can capture either by value(= ) or by reference(&)
	//- you would obviously capture by reference if you want to actually modify that variable﻿
	//https://www.youtube.com/watch?v=5t-_wI7nFdU good explanation for further information.

	int multi = 3, sum = 0;
	int c = count_if(vec.begin(), vec.end(), [](int x) {return !(x % 2); });	//no need of above isEven() function
	cout << "Number of even elements: " << c << endl;
	c = count_if(vec.begin(), vec.end(), [multi](int y) {return !(y % multi); });	//For variable passing in lambda..[multi] can also
	cout << "Multiple of 3: " << c << endl;											//be written as [=]
	for_each(vec.begin(), vec.end(), [&sum](int x) {sum = sum + x; });				//pass by reference instead of by value..since by value gets
	cout << "Sum of elements:" << sum << endl;										//wrong calculation..i.e 0
	_getch();																		
	return 0;
}