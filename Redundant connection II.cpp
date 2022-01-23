/*
Problem Link: https://leetcode.com/problems/redundant-connection-ii/

Redundant Connection II

In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are 
descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.
The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional 
directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting 
nodes ui and vi, where ui is a parent of child vi.
Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer
that occurs last in the given 2D-array.

Example 1:
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Example 2:
Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
Output: [4,1]
 

Constraints:
n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
*/

class Solution {
public:
    
     int findpar(int u, vector<int>& par){
        if(par[u] == u) return u;

        int temp = findpar(par[u], par);
        par[u] = temp;

    return temp;
    }

    bool Union(int a, int b, vector<int> &parent, vector<int> &rank){ 
        
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
            return false;
        } else{
            return true;
        }
        
    return true;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges){
        
        int n = edges.size();
        vector<int> indegree(n+1, -1);
        
        int blist1 = -1, blist2 = -1;
        for(int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(indegree[v] == -1){
                indegree[v] = i;
            } else{
                blist1 = i;
                blist2 = indegree[v];
                break;
            }
        }
        
        vector<int> parent(n+1);
        vector<int> rank(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(int i = 0; i < n; i++){
            if(i == blist1) continue;    // removing edge of 2nd candidate
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            bool flag = Union(u, v, parent, rank);     // detect removing edge 
            
            if(flag == true){
                if(blist1 == -1) return edges[i];      // no one has 2 indegree(2 parent)
                else return edges[blist2];             // 2 parent case, but choose wrong candidate  
            } 
        }
        
    return edges[blist1];  
    }
};


