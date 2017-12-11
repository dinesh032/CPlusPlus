#include<iostream>
#include<conio.h>
#include<vector>

#include "fact.h"

using namespace std;

int main() {
	int n;
	cout << "Enter the number:";
	cin >> n;
	cout << endl << "Factorial of " << n << ":" << factorial(n);
	_getch();
	return 0;
}