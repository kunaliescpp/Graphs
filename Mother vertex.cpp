/* 
Problem Link: https://practice.geeksforgeeks.org/problems/mother-vertex/1/

Mother Vertex 

Given a Directed Graph, find a Mother Vertex in the Graph (if present). A Mother Vertex is a vertex through which we can reach 
all the other vertices of the Graph.
 
Example 1:
Input: 2 -> 1 -> 0 -> 3 -> 4
             ^
             |
             2
Output: 0
Explanation: According to the given edges, all nodes can be reaced from nodes from 0, 1 and 2. But, since 0 is minimum among 0,1 and 3,
so 0 is the output.

Example 2:  
Input: 0 -> 1 <- 2
Output: -1
Explanation: According to the given edges, no vertices are there from where we can reach all vertices. So, output is -1.


Constraints:
1 ≤ V ≤ 500
*/

class Solution {
    public:
    
    void check_candidate(vector<int> adj[], int src, vector<bool>& visited){
        
        visited[src] = true;
        for(int v : adj[src]){
            if(visited[v] == false) check_candidate(adj, v, visited);
        }
    }
    
    void dfs(vector<int> adj[], int src, vector<bool>& visited, stack<int>& stk){
        
        visited[src] = true;
        for(int v : adj[src]){
            if(visited[v] == false){
                dfs(adj, v, visited, stk);
                stk.push(v);
            }
        }
    }

    int findMotherVertex(int V, vector<int>adj[]){
    	//check if there is a path from 1 node to all node
	stack<int> stk;
        vector<bool> visited(V);
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                dfs(adj, i, visited, stk);
                stk.push(i);
            }
        }
	    
        fill(visited.begin(), visited.end(), false);
        //only stk.top() have the capacity to be a mother vertex
        check_candidate(adj, stk.top(), visited);
	    
	for(int i = 0; i < V; i++){
	    if(visited[i] == false) return -1;
	}
	   
     return stk.top();  
     }
};


