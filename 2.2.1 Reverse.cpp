/*
Problem Link: https://www.codechef.com/problems/REVERSE

Sometimes mysteries happen. Chef found a directed graph with N vertices and M edges in his kitchen!

The evening was boring and chef has nothing else to do, so to entertain himself, Chef thought about a question 
"What is the minimum number of edges he needs to reverse in order to have at least one path from vertex 1 to vertex N, 
where the vertices are numbered from 1 to N.

Input
Each test file contains only one test case.
The first line of the input contains two space separated integers N and M, denoting the number of vertices and the number of edges 
in the graph respectively. The ith line of the next M lines contains two space separated integers Xi and Yi, denoting that the ith edge
connects vertices from Xi to Yi.

Output
In a single line, print the minimum number of edges we need to revert. If there is no way of having at least one path from 1 to N, print -1.

Constraints
1 ≤ N, M ≤ 100000 = 10^5
1 ≤ Xi, Yi ≤ N
There can be multiple edges connecting the same pair of vertices, There can be self loops too i.e. Xi = Yi

Example
Input:
7 7
1 2 
3 2
3 4
7 4
6 2
5 6
7 5

Output: 2
Explanation : We can consider two paths from 1 to 7:
1-2-3-4-7
1-2-6-5-7
In the first one we need to revert edges (3-2), (7-4). In the second one - (6-2), (5-6), (7-5). So the answer is min(2, 3) = 2.
*/

#include <bits/stdc++.h>
using namespace std;
//Time complexity : O(E*(log V))
//Space complexity : O(n^2)

//Shortest path from src to all other nodes in the graph
int dijkstra(int src, vector<pair<int, int>> adj[], int n){

   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   // vector<int> distTo(n, INT_MAX);
   vector<int> distTo(n+1, 1e9);
   
   pq.push({0, src});
   distTo[src] = 0;
   while(!pq.empty()){

      int dist = pq.top().first;         //dist Till now
      int u = pq.top().second;
      pq.pop();

      //Update the distance of the adjacent node
      for(auto it = adj[u].begin(); it != adj[u].end(); it++){
         int wt = it->first;           
         int v = it->second;

         if(distTo[v] > wt + dist){
            distTo[v] = wt + dist;
            pq.push({distTo[v], v});
         }
      }
   } // pq is empty  

if(distTo[n] != INT_MAX){
  return distTo[n];
}else{
    return -1;
}  

}

int main(){

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif

   int n, e;
   cin >> n >> e;
   vector<pair<int, int>> adj[n+1];  

   for(int i = 0; i < e; i++){
      int u, v;
      cin >> u >> v;
      adj[u].push_back({0, v}); //{v, wt}
      adj[v].push_back({1, u});
   }

   int ans =  dijkstra(1, adj, n);
   
   if(ans >= 1e9) cout << -1;
   else cout << ans;
   
return 0;
}


