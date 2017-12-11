#include"fact.h"

using namespace std;

int factorial(int n) {
	int fact = n;
	while (n > 1) {
		fact = fact * (n - 1);
		n = n - 1;
	}
	return fact;
}