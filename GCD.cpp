#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N_MAX = 100000;
const int V_MAX = 10000;
const int Q_MAX = 10000;
const int X_MAX = 10000;
const long MODULUS = 1000000007;

findGCDCfSet(long numbers[], int GDC, int N);
		
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N, Q, V;
	long numbers[N_MAX], queries[Q_MAX];
	
	cin >> N;
	for(int i = 0; i < N; i++) { 
		cin >> numbers[i];
	}
	
	cin >> Q;
	for(int i = 0; i < Q; i++) {
		cin >> queries[i];
	}
	
	for(int i = 0; i < Q; i++) {
		findGCDCfSet(numbers[N_MAX], i, N)
	}
	
    return 0;
}

findGCDCfSet(long numbers[], int GDC, int N) {
	int temp[N_MAX];
	int numberCombinations = 0;
	int count = 0;
	
	for(int i = 0; i < N; i++) {
		if((numbers[i] % GDC) == 0) {
			temp[count] = numbers[i];
			count++;
		}
	}
	
	cout << numberCombinations % MODULUS << endl;
}