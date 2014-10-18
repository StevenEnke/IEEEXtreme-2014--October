#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int INT_MAX=2147483647;
int min(int x, int y, int z);
int minCost(vector<vector<int> > cost, int m, int n, int Up);

int main() {
    int N, minMinCost = INT_MAX, currentMinCost;
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
        currentMinCost = minCost(cost, i, N-1, 0);
	cout<< currentMinCost <<endl;
	if(minMinCost > currentMinCost) {
            minMinCost = currentMinCost;
	}
    }
    cout << minMinCost << endl;
    
    return 0;
}

int minCost(vector<vector<int> > cost, int m, int n, int Up)
{
    if (n < 0 || m < 0 || n > 4 || m > 4)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else {
        cout << m << " " << n << endl;
        cout << cost[m][n] << endl;
	// 0 allows up or down, 1 allows only up, 2 allows only down
/*        if(Up == 0)
            return cost[m][n] + min( minCost(cost, m-1, n, 2), minCost(cost, m, n-1, 0), minCost(cost, m+1, n, 1));
        else if(Up == 1)
            return cost[m][n] + min( minCost(cost, -1, -1, 0), minCost(cost, m, n-1, 0), minCost(cost, m+1, n, 1));
        else // Up == 2
	    return cost[m][n] + min( minCost(cost, -1, -1, 0), minCost(cost, m, n-1, 0), minCost(cost, m-1, n, 2));*/
        if(Up == 0)
            return cost[m][n] + min( minCost(cost, m, n-1, 2), minCost(cost, m-1, n, 0), minCost(cost, m, n+1, 1));
        else if(Up == 1)
            return cost[m][n] + min( minCost(cost, -1, -1, 0), minCost(cost, m-1, n, 0), minCost(cost, m, n+1, 1));
        else // Up == 2
	    return cost[m][n] + min( minCost(cost, -1, -1, 0), minCost(cost, m-1, n, 0), minCost(cost, m, n-1, 2));
    }
}

int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}
