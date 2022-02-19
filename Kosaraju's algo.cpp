#include<bits/stdc++.h>
using namespace std;

//topological sorting
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    
    vis[node] = 1; 
    for(auto v: adj[node]) { 
        if(vis[v] == 0) dfs(x, st, vis, adj); 
    } 
    st.push(node); 
}

void revDfs(int node, vector<int> &vis, vector<int> transpose[]){

   cout << node << " ";
   vis[node] = 1;
   for(auto v : transpose[node]){                                   
      if(vis[v] == 0) revDfs(x, vis, transpose);                  
   }
}

int main(){

   int n, e;
   cin >> n >> e;
   
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
      if(vis[i] == 0) dfs(i, st, vis, adj);
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


