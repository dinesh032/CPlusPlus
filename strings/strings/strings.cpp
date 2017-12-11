#include<iostream>
#include<conio.h>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;
int main() {
//string constructors
	string s1 = "Hello";		//or string s1("Hello");
	string s2("Hello",3);		//s2: Hel
	string s3(s1, 2);			//s3: llo  ..notice the diff. to last declaration...3 is size & 2 is index
	string s4(s1, 2, 3);		//s4: llo	..another way of defining..2 is index & 3 is size
	cout << s1 << ", " << s2 << ", " << s3 << ", " << s4;

//size
	s1 = "Dinesh kumar";
	cout << endl << "Length:" << s1.size();		//same as s1.length()
	cout << endl << "Capacity:"<<s1.capacity();	//capacity is allocated size..always bigger than or equal to size() value
	s1.reserve(50);								//changing capacity() value..now capacity = 50 char values
	cout << endl << "Capacity after reserving:" << s1.capacity();
	s1.shrink_to_fit();
	cout << endl << "Shrinked capacity:" << s1.capacity();	//shrinks the capacity to hold the content
	s1.resize(14);				//s1 size is 12..adds 2 \0 to the end of s1
	cout << endl << "Resized string:" << s1;
	s1.resize(12);	//for further purposes, resetting

//single element access
	cout << endl;
	cout << "s1[2] & s1.at(2) " << s1.at(2)<<", "<< s1[2];	//can also change value..eg. s1[2] = 'd' or s1.at(2) = 'd'..s1 becomes didesh kumar
															//generally s1.at(2) is safer as checks out_of_range exception before access
	//some other element access functions
	cout << endl << "s1.front():"<<s1.front() << ", s1.back():" << s1.back();		//s1.front() returns D & s1.back() returns r
	s1.push_back('b');										//pushes 'b' to s1
	cout << endl << "After pushing b:"<< s1;
	s1.pop_back();										//pops last char
	cout << endl << "After poping last:"<< s1;			//Also, s1.begin() & s1.end() iterators also available

//ranged access..mainly assign(), append(), insert(), replace()
	s2.assign(s1);	//same as s1 = s2..but assign() is flexible as shown below
	cout << endl << endl<< "string s2:" << s2;
	s2.assign(s1, 2, 4);
	cout << endl << "s2 with 2, 4 of s1:" << s2;
	
	s1.append(" Biradar");		//appends to s2
	cout << endl << "after append:" << s1;

	s2.insert(0, "Di");
	cout << endl << "s2 after insert:" << s2;

	s2.replace(0, 6, s1, 7, 5);	//here s2 = Dinesh & s1 = Dinesh kumar Biradar..replace() is replacing s2 with kumar substr in s1..argurements
								//are indices first then size later
	cout << endl << "s2 after replace with some part of s1:" << s2;

	cout << endl << "sub string of s2:" << s2.substr(1, 3);		//print substr of s2 from index 1 & 3 elements

//Member function algorithms..copy(), find(), compare()
	//char buf[10];
	//size_t len = s1.copy(buf, 3, 3);
	int found = s1.find("kumar");
	cout << endl << "kumar found at " << found << " in s1";
	found = s1.compare(s2);		//returns +ve if s1>s2, -ve if s1<s2 & 0 if s1=s2

//Non Member functions..reading & writing strings
/*	cout << endl << "Enter the string:";
	getline(cin, s3);	//another way cin>>s3 but stops reading at space..getline() better option
	cout << "-->Entered string" << s3;
*/
//strings and STL algorithms
	s1 = "Arsenal are the best.";
	s2 = "                           ";
	cout << endl << "s1: "<< s1;
	int num = count(s1.begin(), s1.end(),'e');	//returns 4 I think
	cout << endl << "No. of e's in s1:" << num;
	num = count_if(s1.begin(), s1.end(), [](char c) {return (c <= 'e' && c >= 'a'); });	//counter the no. of abcd
	cout << endl << "Instances of a,b,c or d in s1:" << num;
	replace(s1.begin(), s1.end(), 'e', 'z');	//replace all e's with z..different to string replace() member function..there 
												//sub strings were replaced & here chars are replaced
	replace(s1.begin(), s1.end(), 'z', 'e');	//for future handling
	transform(s1.begin(), s1.end(), s2.begin(),
		[](char c) {
		if (c < 'n')
			return 'a';
		else
			return 'z';
	});
	cout << endl << "transformed s2: " << s2;
	reverse(s1.begin(), s1.end());
	cout << endl << "reversed string:" << s1;

	_getch();
	return 0;
}