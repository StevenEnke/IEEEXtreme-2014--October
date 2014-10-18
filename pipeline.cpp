#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N; // NxN pipes
	vector<vector<int>> matrix;
	
	scanf("%d", &N);
	
	matrix.resize(N);
	for(int i = 0; i < N; i++) {
		matrix[i].resize(N);
		for(int j = 0; j < N; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
    return 0;
}
