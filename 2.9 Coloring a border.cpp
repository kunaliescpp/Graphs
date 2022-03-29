/*
Problem Link: https://leetcode.com/problems/coloring-a-border/

Coloring A Border

You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color 
of the grid square at that location.
Two squares belong to the same connected component if they have the same color and are next to each other in any of the 4 directions.
The border of a connected component is all the squares in the connected component that are either 4-directionally adjacent to a square 
not in the component, or on the boundary of the grid (the first or last row or column).
You should color the border of the connected component that contains the square grid[row][col] with color.
Return the final grid.

Example 1:
Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
Output: [[3,3],[3,2]]

Example 2:
Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
Output: [[1,3,3],[2,3,3]]

Example 3:
Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
Output: [[2,2,2],[2,1,2],[2,2,2]]
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j], color <= 1000
0 <= row < m
0 <= col < n
*/

class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void dfs(vector<vector<int>>& grid, int r, int c, int color, vector<vector<bool>>& visited){
        
        visited[r][c] = true;
        int same = 0;  // no. of identical elements in the 4 directions
        
        for(int i = 0; i < 4; i++) {
            
            int x = r + dx[i];
            int y = c + dy[i];
            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;
        
            if(visited[x][y] == true){
                same++; continue;
            }
        
            if(grid[x][y] == grid[r][c]){
                dfs(grid, x, y, color, visited);
                same++;
            }  
        }
    
        if(same < 4) grid[r][c] = color;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        dfs(grid, r0, c0, color, visited);
    
    return grid;
    }
};



//Hint = https://leetcode.com/problems/coloring-a-border/discuss/791470/C%2B%2B-or-Solution-using-DFS-or-Faster-than-99.39-or-With-Explanation 
