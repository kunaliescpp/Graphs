/*
Problem Link: https://leetcode.com/problems/01-matrix/

01 Matrix

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell. The distance between two adjacent cells is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 
 
Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = -1;
            }
        }
    
        while(!q.empty()){
            
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int rowdash = r + dirs[i][0];
                int coldash = c + dirs[i][1];
                
                if(rowdash >= 0 && coldash >= 0 && rowdash < m && coldash < n && mat[rowdash][coldash] < 0){
                    mat[rowdash][coldash] = mat[r][c] + 1;
                    q.push({rowdash, coldash});
                }
            }  
        } // queue is empty
    return mat;
    }
};


