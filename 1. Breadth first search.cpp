/* 
Problem Link: BFS of graph 

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting 
from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected 
from Node 0 in consideration.


Example 1:
Input: 
      0
     / \ \
    1   2 3
        \
         4
Output: 0 1 2 3 4
Explanation: 0 is connected to 1 , 2 , 3. 2 is connected to 4. so starting from 0, it will go to 1 then 2
then 3.After this 2 to 4, thus bfs will be 0 1 2 3 4.

Example 2:
Input:
Output: 0 1 2
Explanation: 0 is connected to 1 , 2. so starting from 0, it will go to 1 then 2, thus bfs will be 0 1 2 3 4. 


Constraints:
1 ≤ V, E ≤ 10^4
*/

class Solution{
  public:
        
    //Time complexity: O(V+E)
    //Space complexity: 
    
    //BFS find paths from source to its 1 edge away vertex (i.e. shortest path)
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    
	    vector<bool> isVisited(V, false);
	   
	    vector<int>v;
	  
	    int src = 0;
        queue<int>q;
        q.push(src);
        isVisited[src] = true;
        for(int i = 0; i < V; i++){                   // visiting n nodees = O(V)
            while(!q.empty()){
                int node = q.front(); q.pop();
                v.push_back(node);
                
                for(int j : adj[node]){               // adj nodes travel = O(E)
                    if(isVisited[j] == false){
                        q.push(j);
                        isVisited[j] = true;
                    }
                }
            }
        }
	return v;
	}
};


