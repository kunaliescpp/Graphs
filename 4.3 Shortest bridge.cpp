/*
Problem Link: https://leetcode.com/problems/shortest-bridge/

Shortest Bridge

You are given an n x n binary matrix grid where 1 represents land and 0 represents water. An island is a 4-directionally connected 
group of 1's not connected to any other 1's. There are exactly two islands in grid. You may change 0's to 1's to connect the two 
islands to form one island. Return the smallest number of 0's you must flip to connect the two islands.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 

Constraints:
n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.
*/

class Solution {
public:
    
    void dfs(int r, int c, queue<pair<int, int>>& q, vector<vector<int>>& grid){
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] != 1) return;
        
        grid[r][c] = -1;
        q.push({r, c});
        dfs(r+1, c, q, grid);
        dfs(r, c+1, q, grid);
        dfs(r-1, c, q, grid);
        dfs(r, c-1, q, grid);
    }
    
    int shortestBridge(vector<vector<int>>& grid){
    
        int m = grid.size(), n = grid[0].size();
        
        bool check = false;
        queue<pair<int, int>> q;   
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, q, grid);
                    check = true;
                    break;
                }
            }
            if(check) break;
        } 
    
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int cnt = 0;
        while(!q.empty()){
            
            int k = q.size();
            while(k--){
                int f = q.front().first; 
                int s = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int rowdash = f + dirs[i][0];
                    int coldash = s + dirs[i][1];

                    if(rowdash >= 0 && coldash >= 0 && rowdash < m && coldash < n && grid[rowdash][coldash] != -1){
                        if(grid[rowdash][coldash] == 1) return cnt;
                        grid[rowdash][coldash] = -1;
                        q.push({rowdash, coldash});
                    }
                }
            }
        cnt++;
        } // q is empty
    return cnt;
    }
};


