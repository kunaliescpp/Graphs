/* 
Problem Link: https://www.codingninjas.com/codestudio/problems/connecting-cities-with-minimum-cost_1386586

Connecting Cities With Minimum Cost

There are ‘N’ cities numbered from 1 to ‘N’ and ‘M’ roads. Each road connectss two different cities and described as a two-way road
using three integers (‘U’, ‘V’, ‘W’) which represents the cost ‘W’ to connect city ‘U’ and city ‘V’ together.
Now, you are supposed to find the minimum cost so that for every pair of cities, there exists a path of connections (possibly of length 1) 
that connects those two cities together. The cost is the sum of the connection costs used. If the task is impossible, return -1.

Input Format :
The first line of input contains an integer ‘T’ denoting the number of test cases. Then each test case follows.
The first line of each test case contains two single space-separated integers ‘N’ and ‘M’ denoting the number of cities and roads respectively.
Each of the next ‘M’ lines contains three single space-separated integers ‘U’, ‘V’, and ‘W’ denoting a two-way road between city ‘U’ and ‘V’ of cost ‘W’.

Sample Input 1 :
2
5 6
1 2 6
2 3 5
3 4 4
1 4 1
1 3 2
3 5 3
3 1
1 2 4
Sample Output 1 :
11
-1
Explanation Of Sample Output 1 : For the first test case, the graph below describes the connection between the cities:
We can choose the following roads to connect all the cities getting minimum cost:
And its cost is 1 + 2 + 5 + 3 = 11
For the second test case, there is no way to connect all cities. So print -1.

Sample Input 2 :
2
3 3
1 2 1
2 3 2
3 1 3
4 3
1 2 4
2 3 5
3 4 1
Sample Output 2 :
3
10
Explanation Of Sample Output 2 : For the first test case, the minimum cost will be 3. For the second test case, the minimum cost will be 10.
*/

#include<bits/stdc++.h>

int prims(int n, int src, vector<bool>& visited, vector<pair<int, int>>adj[]){
    
    int sum = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
    
        if(visited[node] == true) continue;
        visited[node] = true;
        sum += dist;
        for(pair<int, int> v : adj[node]){
            if(visited[v.first] == false){
                pq.push({v.second, v.first});
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(visited[i] == false) return -1;
    }
    
return sum;
}

int getMinimumCost(int n, int m, vector<vector<int>> &connections){
	
    vector<pair<int, int>> adj[n+1];
    for(int i = 0; i < m; i++){
        int u = connections[i][0];
        int v = connections[i][1];
        int wt = connections[i][2];
        
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<bool>visited(n+1, false);
    int cost = prims(n, 1, visited, adj);

return cost;
}


