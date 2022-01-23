/*
Problem Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

DFS of Graph 

Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right
according to the graph..


Example 1:
           0
         / \ \
        1  2  4
             /
            3

Output: 0 1 2 4 3
Explanation: 0 is connected to 1, 2, 4. 1 is connected to 0. 2 is connected to 0. 3 is connected to 4. 4 is connected to 0, 3.
so starting from 0, it will go to 1 then 2 then 4, and then from 4 to 3. Thus dfs will be 0 1 2 4 3.

Example 2:
Input:
          0
         / \
        1   3
       / 
      2  
Output: 0 1 2 3
Explanation: 0 is connected to 1 , 3. 1 is connected to 2.  2 is connected to 1. 3 is connected to 0. 
so starting from 0, it will go to 1 then 2 then back to 0 then 0 to 3 thus dfs will be 0 1 2 3. 


Constraints:
1 ≤ V, E ≤ 10^4
*/

class Solution {
    public:
    void dfs(int V, int source, bool visited[], vector<int> adj[], vector<int>& v){
        visited[source] = true;
        v.push_back(source);
        for(int j : adj[source]){
            if(visited[j] == false) dfs(V, j, visited, adj, v);
        }
    }
    
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    
	    bool visited[V];
	    for(int i = 0; i < V; i++) visited[i] = false;
	    
	    vector<int>v ;
	    dfs(V, 0, visited, adj, v);
	    
    return v;
	}
};


