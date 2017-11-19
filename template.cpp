#include<iostream>

using namespace std;

//Template function declaration
template <typename T>
T square(T x) {
	return x*x;
}
//Template class declaration
//template <class T> 
//class name{
// T value;
//};
//name<int> obj; object defination

int main() {
	
	cout<<square(5)<<endl;
	cout<<square(5.5)<<endl;
	return 0;
}
