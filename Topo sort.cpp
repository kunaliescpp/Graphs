/* 
Problem Link: https://practice.geeksforgeeks.org/problems/topological-sort/1

Topological sort 
Medium Accuracy: 40.0% Submissions: 73948 Points: 4
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.


Example 1:

Input:
           1 ---> 0 <--- 2
                  ^
                  |
                  3
Output:
1
Explanation: The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the graph is 3, 2, 1, 0.

Constraints:
2 ≤ V ≤ 10^4
1 ≤ E ≤ (N*(N-1))/2
*/

class Solution{
	public:
	
//if u is dependent on v then u must print first  (3, 2, 1, 0)
	vector<int> topoSort(int V, vector<int> adj[]) {
	    
	    vector<int> indegree (V);
	    for(int i = 0; i < V; i++){
	        for(int j : adj[i]){
	            indegree[j]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i = 0; i < V; i++){
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    int cnt = 0;
	    vector<int>v;
	    while(!q.empty()){
	        int f = q.front(); q.pop();
	        v.push_back(f);
	      
	       for(int j : adj[f]){
	          indegree[j]--;
	          if(indegree[j] == 0) q.push(j);
	       }
	    }
	    
	return v;
	}
};


