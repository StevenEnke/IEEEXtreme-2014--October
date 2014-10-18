#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const MAX_N_NUMBERS = 100000;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N, M, K;
	vector<int> numbers;
	
	// First line of the input will contain three integers N, M and K separated by spaces respectively. 
	cin >> N;
	cin >> M;
	cin >> K;
	
	// Second line of the input will contain N integers separated by spaces in clockwise order starting from an arbitrary location. 
	numbers.resize (N);
	for(int i = 0; i < N; i++) 
	{
		cin >> numbers[i];
	}
	
    return 0;
}
