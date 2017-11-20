#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

string timeConversion(string s) {
	// Complete this function

	string sub1 = s.substr(0, 2);
	string sub2 = s.substr(8, 2);
	int time = stoi(sub1);
	if (time == 12 && sub2 == "AM") {
		sub1 = "00";
		s.replace(0, 2, sub1);
		s.erase(8, 2);
		return s;
	}
	else if(time == 12 && sub2 == "PM") {
		s.erase(8, 2);
		return s;
	}
	else if (time < 12 && sub2 == "PM"){
		time = time + 12;
		sub1 = to_string(time);
		s.replace(0, 2, sub1);
		s.erase(8, 2);
		return s;
	}
	else {
		s.erase(8, 2);
		return s;
	}
	//return s;
}

int main() {
	string s;
	cin >> s;
	string result = timeConversion(s);
	cout << result << endl;
	_getch();
	return 0;
}