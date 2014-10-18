#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int n, int v[], int w[], int C);
void quickSort(int arr[], int left, int right);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int N, M, i; // Number robbers, capacity of each robbers
	string itemName[5];
	string itemLoad[5];
	string itemValue[5];
	int valueAmount[5];
	int loadAmount[5];
	int totalCapacity;
	string line;
	float ratio;
	
	
	vector<int. someVector;
	
	someVector[someVector.size()-1]
	
	cin >> N;
	cin >> M;
	i = 0;
	while(getline(cin, line)) {
		if(line != "END") {
			getline(cin, itemName[i], ',');
			getline(cin, itemLoad[i], ',');
			getline(cin, itemValue[i], ' ');
		}
		i++;
	}
	
	for(int k = 0; k < i; k++) { 
		valueAmount[k] = atoi(itemValue[k].c_str());
		loadAmount[k] = atoi(itemLoad[k].c_str());
	}	
	
	for(int j = 0; j < i; j++) {
		ratio = valueAmount[j] / loadAmount[j];
	}
	
	totalCapacity = N*M;
	knapsack(i, valueAmount,loadAmount, totalCapacity);
	
    return 0;
}
int
int knapsack(int n, int v[], int w[], int C) {
	vector<int> v_per_w (n);
	int currentC;
	int value, i;
	
    for(int i = 0; i < n; i++) {
        v_per_w[i] = (v[i] / w[i]);
	}
	
    quickSort(v_per_w);
    
    i = 0;
    currentC = 0;
    while (currentC + w[i] < C) {
        currentC += w[i];
		value += v[i];
        i++;
    }
	
    return value;
} 

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */

	while (i <= j) {
		while (arr[i] > pivot) {
			i++;
			while (arr[j] < pivot) {
				j--;
				if (i <= j) {
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
					i++;
					j--;
				}
			}
		}
	}

	/* recursion */

	if (left < j) {
		quickSort(arr, left, j);
	}
	
	if (i < right) {
		quickSort(arr, i, right);
	}
}