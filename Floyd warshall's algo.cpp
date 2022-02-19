/*
Problem Link: https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

Find shortest distances between every pair of vertices in a given edge weighted directed Graph. 
*/

// Time complexity : O(V^3)
#include <bits/stdc++.h>
using namespace std;

void floydWarshall(int n, vector<vector<int>> graph){

	int dist[n][n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			dist[i][j] = graph[i][j];
		}
	}

    // dist = min(curr, another src->des distance)
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
        if(dist[i][j] > (dist[i][k] + dist[k][j])){
          dist[i][j] = dist[i][k] + dist[k][j];
        } 
			}
		} 
	} // loop ends
  
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if (dist[i][j] == INT_MAX) cout << "INF"<< " ";
			else cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int n, cin >> n;
	int e; cin >> e;
	vector<vector<int>> graph;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j];
		}
	}

	floydWarshall(n, graph);
  
return 0;
}


// Input
  // int graph[V][V] = { { 0,    5,   INF,   10},
  //                     {INF,   0,   3,   INF},
  //                     {INF, INF,   0,    1},
  //                     {INF, INF,  INF,   0}};

// output
//   0      5      8      9
// INF      0      3      4
// INF    INF      0      1
// INF    INF    INF      0


