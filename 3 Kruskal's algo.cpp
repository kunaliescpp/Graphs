/*
Problem Link: https://www.codingninjas.com/codestudio/problems/kruskal-s-minimum-spanning-tree-algorithm_1082553

Kruskal’s Minimum Spanning Tree Algorithm

You have been given a connected undirected weighted graph. Your task is to find the weight of the minimum spanning tree of the given graph.
A minimum spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, 
without any cycles, and with the minimum possible total edge weight. A spanning tree’s weight is the sum of weights given to each edge of
the spanning tree.

Constraints :
1 <= T <= 50
1 <= N <= 10000
1 <= M <= 10000
1 <= W <= 1000
1 <= U, V <= N

Input :
2
5 6
1 2 6
2 3 5
3 4 4
1 4 1
1 3 2
3 5 3
2 1
1 2 4

Output :
11
4
*/

#include<bits/stdc++.h>
using namespace std;
//Time complexity : O(E log E + V +  E*alpha(V)) = O(E* log E)
//Space complexity : O(E) + O(N) + O(N) = O(N)
class edge{
   
   public:

   int src;
   int des;
   int wt;

   edge(int first, int second, int weight){
      src = first;
      des = second;
      wt = weight;
   }
};

// Comparator for sorting edges in increasing order of their weights
bool mycmp(edge e1, edge e2){
    return e1.wt < e2.wt;
}

int findpar(int u, vector<int>& parent){
   if(parent[u] == u) return u;

   int temp = findpar(parent[u], parent);
   parent[u] = temp;

return temp;
}

void Union(int a, int b, vector<int>& parent, vector<int>& rank){

   int p1 = findpar(a, parent);
   int p2 = findpar(b, parent);

   if(p1 != p2){
       
       if(rank[p1] < rank[p2]){
           parent[p2] = p1;
       }
       else if(rank[p1] > rank[p2]){
           parent[p1] = p2;
       }
       else{
           parent[p2] = p1;
           rank[p1]++;
       }
   }
}
       
int main(){

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif

   int n, e;
   cin >> n >> e;

   vector<edge> edges;
   for(int i = 0; i < e; i++){
      int u, v, weight;
      cin >> u >> v >> weight;
      edges.push_back(edge(u, v, weight));
      edges.push_back(edge(v, u, weight));
   }

   sort(edges.begin(), edges.end(), mycmp);

   vector<int> parent(n);
   vector<int> rank(n);
   for(int i = 0; i < n; i++){
      parent[i] = i;
      rank[i] = 1;
   }

   int cost = 0;
   vector<pair<int, int>> mst;
   for(auto x : edges){
      
      if(findpar(x.src, parent) != findpar(x.des, parent)){
         // If both sets are different, perform union 
         //And add this edge to our final MST, hence add its weight to final weight
         cost += x.wt;
         mst.push_back({x.src, x.des});
         Union(x.src, x.des, parent, rank);
      }
   }

   cout << cost << endl;
   for(auto x : mst){
      cout << x.first << "-" << x.second << endl;
   }

return 0;
}


