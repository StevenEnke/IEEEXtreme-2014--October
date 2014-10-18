#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MODULUS = 1000000007;

void cycle(vector<int>& numArray, int cycle);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N;
	int Q;
	int output = 0;
	
	// Getting number of Integers
	cin >> N;
	
	// Storing integers
	vector<int> numbers (N);
	
	for(int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	
	// Getting number of operations
	cin >> Q;
	
	// Storing operations
	vector<int> operations (Q);
	
	for(int i = 0; i < Q; i++) {
		cin >> operations[i];
	}
	
	// 
	for(int i = 0; i < Q; i++) {
		cycle(numbers, operations[i]);
	}
	
	for(int i = 0; i < N; i++) {
		output += numbers[i];
	}
	
	output = output % MODULUS;
	
	cout << output << endl;
	
    return 0;
}

void cycle(vector<int>& numArray, int cycle) {
	int length = numArray.size();
	vector<int> temp (length);
	
	for(int i = 0; i < length; i++) {
		temp[i] = numArray[i] + numArray[(i-cycle+length)%length];
	}
	
	for(int i = 0; i < length; i++) {
		numArray[i] = temp[i];
	}
	
	return;
}