#include<iostream>

using namespace std;

void printInt(int& i) { 
	cout<<"lvalue reference: "<< i << endl;
}
void printInt(int&& i){
	cout<<"rvalue reference: " << i << endl;
}

int main() {

//	C++ 11: Rvalue reference
//	why it's used?
//	1. Moving semantics
//	Move Constructor/Move Assignment Operator.
//	C++11 defines as extra constructor for rvalue parameters in functions. It's called move constructor which take paramters by reference.
//	Purpose: to avoid costly & unnecessary deep copying, rvalue particularly powerful where passing by val & ref both
//	are used. All C++11 containers use move semantics, so passing by value & by ref is same as pass by reference in C++11.
//	2. Perfect forwarding
//	
//
//
	int a = 5;	//lvalue
	printInt(a);	//calls printInt(&i)--> lvalue reference
	printInt(6);	//calls printInt(&&i)--> rvalue reference
	return 0;
}
