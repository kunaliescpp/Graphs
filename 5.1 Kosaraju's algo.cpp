/* Problem Link: https://www.geeksforgeeks.org/strongly-connected-components/?ref=lbp

Given a directed graph, find out whether the graph is strongly connected or not. A directed graph is strongly connected 
if there is a path between any two pair of vertices.
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &stk, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1; 
    for(auto x: adj[node]) { 
        if(vis[x] == 0) dfs(x, stk, vis, adj); 
    } 
    stk.push(node); 
}

void revDfs(int node, vector<int> &vis, vector<int> transpose[]){
   cout << node << " ";
   vis[node] = 1;
   for(auto x : transpose[node]){                                   
      if(vis[x] == 0) revDfs(x, vis, transpose);                  
   }
}

int main(){
   int n; cin >> n;
   int e; cin >> e;
   
   vector<int> adj[n];
   for(int i = 0; i < e; i++){
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
   }

   // step 1-> Topo sort
   vector<int> vis(n, 0);
   stack<int> stk;
   for(int i = 0; i < n; i++){
      if(vis[i] == 0) dfs(i, stk, vis, adj);
   }

  // step 2-> tranpose the adjacency list
   vector<int> transpose[n];
   for(int i = 0; i < n; i++) {
      vis[i] = 0; 
      for(auto v: adj[i]) {
         transpose[v].push_back(i); 
      }
   }

   // step 3-> DFS according to finishing time (stk top-> bottom)
   while(!stk.empty()){
      int node = stk.top();
      stk.pop();
      if(vis[node] == 0){
         revDfs(node, vis, transpose);
         cout << endl;
      }
   }

return 0;
}


