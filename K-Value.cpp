#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void countingSort(int numbersToSort[]m int numElements);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N, M, K, output;
	vector<int> numbers;
	
	// First line of the input will contain three integers N, M and K separated by spaces respectively. 
	cin >> N;
	cin >> M;
	cin >> K;
	
	// Second line of the input will contain N integers separated by spaces in clockwise order starting from an arbitrary location. 
	numbers.resize (N);
	for(int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	
	// Sorting code in ascending order using sort function from algorith library
	sort(numbers.begin(), numbers.end()); 
	
	// Finding K-th value_comp
	output = numbers[K-1];
	
	cout << output;
    return 0;
}
