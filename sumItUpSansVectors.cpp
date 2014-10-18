#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long MODULUS = 1000000007;
const int N_MAX = 100000;
const int Q_MAX = 1000000;

void cycle(unsigned long long numArray[], int cycle, int length);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N, Q, operations[Q_MAX];
	unsigned long long numbers[N_MAX];
	unsigned long long output = 0;
	
	// Getting number of Integers
	cin >> N;
		
	for(int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	
	// Getting number of operations
	cin >> Q;
		
	for(int i = 0; i < Q; i++) {
		cin >> operations[i];
	}
	
	// Processing Information
	for(int i = 0; i < Q; i++) {
		cycle(numbers, operations[i], N);
	}
	
	for(int i = 0; i < N; i++) {
		output += numbers[i];
	}
	cout << numbers[0] << endl;
	cout << output << endl;
	cout << output % MODULUS << endl;
	
    return 0;
}

void cycle(unsigned long long numArray[], int cycle, int length){
	unsigned long long temp[N_MAX];
	
	for(int i = 0; i < length; i++) {
		temp[i] = numArray[i] + numArray[(i-cycle+length)%length];
	}
	
	for(int i = 0; i < length; i++) {
		numArray[i] = temp[i];
	}
	
	return;
}