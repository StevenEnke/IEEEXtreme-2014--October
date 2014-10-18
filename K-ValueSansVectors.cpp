#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N, M, K, minFoundK, subSeqK; // subSeqK is the K-th term for a particular subsequence. minFoundK is the minimum Kth term through all subsequences
	int numbers[2*MAX_N];
	int subSequence[MAX_N];
	
	// First line of the input will contain three integers N, M and K separated by spaces respectively. 
	cin >> N;
	cin >> M;
	cin >> K;
		
	// Second line of the input will contain N integers separated by spaces in clockwise order starting from an arbitrary location.
	for(int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	for(int i = 0; i < M; i++) {
		numbers[N + i] = numbers[i];
	}
	
	// K-th value for first subsequence
	for(int i = 0; i < M; i++) {
		subSequence[i] = numbers[i];
	}
	
	sort(subSequence.begin(), subSequence.end());
	minFoundK = subSequence[K-1];

	// Finding all sub-sequences and finding K-th value from each one, keeping min K
	for(int i = 0; i < N+1; i++) {
		for(int j = 0; j < M; j++) {
			subSequence[j] = numbers[i + j];
		}
		
		sort(subSequence.begin(), subSequence.end());
		subSeqK = subSequence[K-1];

		if(minFoundK > subSeqK) {
			minFoundK = subSeqK;
		}
	}	
	cout << minFoundK;
    return 0;
}

