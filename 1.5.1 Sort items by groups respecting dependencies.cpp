/*
Problem Link: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/

Sort Items by Groups Respecting Dependencies

There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal
to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.

Return a sorted list of the items such that:
The items that belong to the same group are next to each other in the sorted list.
There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
Return any solution if there is more than one solution and return an empty list if there is no solution.

Example 1:
Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
Output: [6,3,4,1,5,2,0,7]

Example 2:
Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
Output: []
Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
 

Constraints:
1 <= m <= n <= 3 * 10^4
group.length == beforeItems.length == n
-1 <= group[i] <= m - 1
0 <= beforeItems[i].length <= n - 1
0 <= beforeItems[i][j] <= n - 1
i != beforeItems[i][j]
beforeItems[i] does not contain duplicates elements.
*/

class Solution {
public:
    
    void topoSort(int src, int n, unordered_map<int, vector<int>>& adj, vector<int>& indegree, vector<int>& ans){
        
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int f = q.front(); q.pop();
            if(f < n) ans.push_back(f);
            
            for(int nxt: adj[f]){
                indegree[nxt]--;
                if(indegree[nxt] == 0) q.push(nxt);
            } 
        }
    } 
      
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        //Step 1-> Maintaining sp & ep of Dummy nodes
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n; i++){
            if(group[i] >= 0){
                int sp = n + group[i];
                int ep = n + group[i] + m;
                adj[sp].push_back(i);
                adj[i].push_back(ep);
            }
        }
    
        //Step 2-> handling beforeItems 
        for(int i = 0; i < beforeItems.size(); i++){
            for(int j = 0; j < beforeItems[i].size(); j++){
                int gbi =  group[beforeItems[i][j]];             // grp of before item;
                int gcurr = group[i];                            // grp of curr item;
            
                if(gbi == -1 && gcurr == -1){
                    adj[beforeItems[i][j]].push_back(i);
                }
                
                else if(gbi == -1){
                    int sp = n + gcurr; 
                    adj[beforeItems[i][j]].push_back(sp);
                }
                
                else if(gcurr == -1){
                    int ep = n + m + gbi;
                    adj[ep].push_back(i);
                }
            
                else{
                    if(gbi == gcurr){
                        adj[beforeItems[i][j]].push_back(i);
                    } else{
                        int ep = n + m + gbi;
                        int sp = n + gcurr;
                        adj[ep].push_back(sp);
                    }
                }
            }   
        }
        
        //Step 3-> Topo_sort items
        vector<int> indegree(n+2*m, 0);
        for(int i = 0; i < n+2*m; i++){
            for(auto v : adj[i]){
                indegree[v]++;
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                ans.push_back(i);
                for(int nxt: adj[i]) indegree[nxt]--;
            } 
        }
        
        for(int i = n; i < n+m; i++){
            if(indegree[i] == 0) topoSort(i, n, adj, indegree, ans);
        }
        
        if(ans.size() != n) return {};
        
    return ans;
    }
};


