#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long MODULUS = 1000000007;
const int N_MAX = 100000;
const int Q_MAX = 1000000;

void cycle(long numArray[], int cycle, int length);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N, Q, operations[Q_MAX];
	long numbers[N_MAX];
	long output = 0;
	
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
		
	cout << output % MODULUS << endl;
	
    return 0;
}

void cycle(long numArray[], int cycle, int length){
	long temp[N_MAX];
	
	for(int i = 0; i < length; i++) {
		temp[i] = numArray[i] + numArray[(i-cycle+length)%length];
	}
	
	for(int i = 0; i < length; i++) {
		numArray[i] = temp[i];
	}
	
	return;
}