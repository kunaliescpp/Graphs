/*
Problem Link: https://practice.geeksforgeeks.org/problems/doctor-strange2206/1

Doctor Strange 

Kamar-taj is a place where "The Ancient One" trains people to protect earth from other dimensions. The earth is protected by N sanctums,
destroying any of it will lead to invasion on earth. The sanctums are connected by M bridges.
Now , you being on dormammu's side , want to find the number of sanctum destroying which will disconnect the sanctums.

Example 1:
Input: N = 5, M = 5
arr[] = {{1,2},{1,3},{3,2},{3,4},{5,4}}
Output : 2
Explanation: 
1.Removing 1 will not make graph disconnected (2--3--4--5). 
2.Removing 2 will also not make graph disconnected(1--3--4--5).
3.Removing 3 makes graph disconnected (1--2 and 4--5).
4.Removing 4 makes graph disconnected (1--2--3--1 and 5).
5.Removing 5 also doesn't makes graph disconnected(3--1--2--3--4).
6.Therefore,there are two such vertices, 3 and 4,so the answer is 2.

Example 2:
Input : N = 2, M = 1 
arr[] = {{1, 2}}
Output : 0

Constraints:
1 ≤ n ≤ 30000
1 ≤ m ≤ 30000
1 ≤ u, v ≤ n
*/

class Solution{
    public:
    
    // Time complexity : O(n + e)                     space complexity : O(2*n)
    void dfs(int src, vector<int>& parent, vector<bool>& vis, vector<int>& tin, vector<int>& low, int timer, vector<int> adj[], vector<bool> &isArticulation){
    
       int child = 0;
       vis[src] = true;
       tin[src] = low[src] = timer;
       timer++;
       for(auto x : adj[src]){
          //cycle exist
          if(x == parent[src]) continue;
          // DFS
          if(vis[x] == false){                             // adj is not visited
             parent[x] = src;
             child++;
             dfs(x, parent, vis, tin, low, timer, adj, isArticulation);
             low[src] = min(low[src], low[x]);
             
             // outer node of cycle (bridge)
             if(low[x] >= tin[src] && parent[src] != 0) isArticulation[src] = true;
             
             if(parent[src] == 0 && child > 1) isArticulation[src] = true;
             
          } else{                                           // inner node of cycle 
                low[src] = min(low[src], tin[x]);
          }
       } 
    }
    
    int doctorStrange(int n, int m, vector<vector<int>> &graph){
         
        vector<int> parent(n+1, 0);
        vector<int> tin(n+1);      // time of insertion
        vector<int> low(n+1);      // lowest time of insertion
        vector<bool> vis(n+1, false);
        vector<bool> isArticulation(n+1, false);
        int timer = 1;
    
        vector<int> adj[n+1];
        for(int i = 0; i < m; i++){
            adj[graph[i][0]].push_back(graph[i][1]);
            adj[graph[i][1]].push_back(graph[i][0]);
        }
    
        // for(int i = 0; i <= n; i++){
        //     low[i] = i;
        // }
        // for(int i = 1; i <= n; i++){
        //   if(vis[i] == false){
              dfs(1, parent, vis, tin, low, timer, adj, isArticulation);
        //   }
        // }
        
        int cnt = 0;
        for(int i = 1; i <= n; i++){
          if(isArticulation[i] == true) cnt++;
        }
    
    return cnt;       
    }
};


