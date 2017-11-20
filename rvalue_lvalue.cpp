#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	
	
	//lvalue - An object which occupies an identifiable memory location
	//rvalue - Any object other than lvalue
	int i;	//i is a lvalue
	i = i + 1; //i+1 is rvalue because it can't be dereferenced
	return 0;
}
