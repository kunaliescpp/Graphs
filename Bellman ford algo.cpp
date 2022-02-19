#include<bits/stdc++.h>
using namespace std;

// This fxn returns 1 if there is -ve weight cycle otherwise returns 0
int bellmanFord(int n, vector<pair<int, int>> adj[]){

   int wt[n];  // distTo
   fill(wt, wt+n, INT_MAX);
   wt[0] = 0;
   int cnt = n;
   while(cnt--){  //relax all edges n-1 times (shortest dis), if dist also decreses at nth time then there exist a negative cycle
      for(int i = 0; i < n; i++){
         if(wt[i] == INT_MAX) continue;
         for(auto x: adj[i]){
            int sum = wt[i] + x.second;
            if(cnt == 0 && sum < wt[x.first]) return 1;
            if(sum < wt[x.first]) wt[x.first] = sum;
         }
      }
   } // while loop ends
return 0;
}

int main(){
   int n, e;
   cin >> n >> e;
   
   vector<pair<int, int>> adj[n];
   for(int i = 0; i < e; i++){
      int u, v, wt;
      cin >> u >> v >> wt;
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
   }

   int ans = bellmanFord(n, adj);
   cout << ans;

return 0;
}


