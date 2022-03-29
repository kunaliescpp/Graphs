/* 
Problem Link: https://leetcode.com/problems/number-of-islands/

Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all
four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

class Solution {
public:
    void drawTreeForComponent(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        
        int m = grid.size();
        int n = grid[0].size();
        
        //base case
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || visited[i][j] == true) return;
    
        visited[i][j] = true;
        drawTreeForComponent(grid, i-1, j, visited);
        drawTreeForComponent(grid, i, j-1, visited);
        drawTreeForComponent(grid, i+1, j, visited);
        drawTreeForComponent(grid, i, j+1, visited);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){   
                    drawTreeForComponent(grid, i, j, visited);
                    cnt++;
                }
            }
        }
    return cnt;
    }
};


