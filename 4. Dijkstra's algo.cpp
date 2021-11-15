/*
Problem Link: https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469

Dijkstra's shortest path

You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) 
will have a weight denoting the distance between node ‘X’ and node ‘Y’.
Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph.

input:
2
5 7
0 1 7
0 2 1
0 3 2
1 2 3
1 3 5 
1 4 1
3 4 7
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6

Output:
0 4 1 2 5
0 5 8 7
*/

#include <bits/stdc++.h>
using namespace std;

//Time complexity : O(e* log n)
//Space complexity : O(n^2)

//Shortest path from src to all other nodes in the graph
int dijkstra(int src, vector<pair<int, int>> adj[], int n){

   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   vector<int> distTo(n, INT_MAX);
   // vector<bool> visited(n, false);
   
   distTo[src] = 0;
   pq.push({0, src});
   while(!pq.empty()){

      int dist = pq.top().first;    //dist till now
      int u = pq.top().second;
      pq.pop();
      for(auto it = adj[u].begin(); it != adj[u].end(); it++){
         int v = it->first;
         int wt = it->second;

         if(distTo[v] > dist + wt){
            distTo[v] = dist + wt;
            pq.push({distTo[v], v});
         }
      }
   } // pq is empty  

return distTo[n-1];                  
}

int main(){

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif

   int n, e;
   cin >> n >> e;
   vector<pair<int, int>> adj[n];  

   for(int i = 0; i < e; i++){
      int u, v, wt;
      cin >> u >> v >> wt;
      adj[u].push_back(make_pair(v, wt)); //{v, wt}
      adj[v].push_back(make_pair(u, wt));
   }

   int ans =  dijkstra(0, adj, n);

   if(ans == INT_MAX) return -1;
   else return ans;
   
return 0;
}


