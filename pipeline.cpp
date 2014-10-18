#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int INT_MAX=2147483647;
int min(int x, int y, int z);
int minCost(vector<vector<int> > cost, int m, int n, int Up, int N);

int main() {
    int N;
    int minMinCost = INT_MAX, currentMinCost;
    scanf("%d",&N);
    vector<vector<int> > cost;
    cost.resize(N);
    
    
    for(int i=0; i<N; i++)
    {
        cost[i].resize(N);
        
        for(int j=0; j<N; j++)
        { 
            scanf("%d",&cost[i][j]);
        }
    }
    
    for(int i = 0; i < N; i++) {
        currentMinCost = minCost(cost, i, N-1, 0, N);
	cout<< currentMinCost <<endl;
	if(minMinCost > currentMinCost) {
            minMinCost = currentMinCost;
	}
    }
    cout << minMinCost << endl;
    
    return 0;
}

int minCost(vector<vector<int> > cost, int m, int n, int Up, int N)
{
    if (n < 0 || m < 0 || n > N-1 || m > N-1)
        return INT_MAX/2;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else {
//        cout << m << " " << n << endl;
//        cout << cost[m][n] << endl;
	// 0 allows up or down, 1 allows only up, 2 allows only down
        if(Up == 0)
            return cost[m][n] + min( minCost(cost, m-1, n, 2, N), minCost(cost, m, n-1, 0, N), minCost(cost, m+1, n, 1, N));
        else if(Up == 1)
            return cost[m][n] + min( minCost(cost, -1, -1, 0, N), minCost(cost, m, n-1, 0, N), minCost(cost, m+1, n, 1, N));
        else // Up == 2
	    return cost[m][n] + min( minCost(cost, -1, -1, 0, N), minCost(cost, m, n-1, 0, N), minCost(cost, m-1, n, 2, N));
    }
}

int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}
