#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string theProgram(int number);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	string input, output;
	int number;
	
	getline(cin, input, '.');
	
	number = atoi(input.c_str());
	
	// "The Program"
	output = theProgram(number);
    
	cout << output;
	
    return 0;
}

string theProgram(int number) {
	stack S;
	
	S.push(number);
	
	number = number^;
	
	return output;
}