/* 
Problem Link: https://www.spoj.com/problems/MST/

Minimum spanning tree

Find the minimum spanning tree of the graph.

Example
Input:
4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40

Output: 17
*/

#include<bits/stdc++.h>
using namespace std;
 
// Time Complexity : O((n + e)*log n)
// Space complexity : O(n)
int prims(int src, vector<pair<int, int>> adj[], int n){
 
   vector<bool> visited(n+1, false);
   priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;   
    
   pq.push({0, src});   // pq({wt, vertex})
   int ans = 0 ;
   while(!pq.empty()){
        
      int wt = pq.top().first;
      int node = pq.top().second;
      pq.pop();
 
      if(visited[node] == true) continue;
      
      ans += wt;
      visited[node] = true;      
      for(pair<int, int> x : adj[node]){    // add unvisited nbr of node
         if(visited[x.first] == false){
            pq.push({x.second, x.first});
         }  
      }
   }//queue is empty
 
   for(int i = 1; i <= n; i++){
    if(visited[i] == false) return -1;
   }
 
return ans;
}
 
int main(){

  int n, e;
  cin >> n >> e;
  vector<pair<int,int>> adj[n+1]; 

  for(int i = 0; i < e ; i++){
      int u, v, wt;
      cin >>  u >> v >> wt;
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
  }   

  int sum = prims(1, adj, n);
  cout << sum << endl;
 
return 0;
}
 

