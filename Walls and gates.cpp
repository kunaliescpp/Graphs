/*
Problem Link: https://www.lintcode.com/problem/663/

Walls and Gates

You are given a m x n 2D grid initialized with these three possible values.
-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a
gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a Gate, that room should remain filled with INF

Example: 
Example1: 
Input: [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
Explanation:
the 2D grid is:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
 0   -1 INF INF
the answer is:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
  
Example2:
Input: [[0,-1],[2147483647,2147483647]]
Output: [[0,-1],[1,2]]
*/

class Solution {
public:

    void wallsAndGates(vector<vector<int>> &rooms){
        
        int m = rooms.size();
        if(m == 0) return;
        int n = rooms[0].size();

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0) q.push({i, j});
            }
        }

        int dis = 0;
        while(!q.empty()){
            
            int k = q.size();
            dis++;
            while(k--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int x = r + dx[i];
                    int y = c + dy[i];

                    if(x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] != -1 && dis < rooms[x][y]){
                        rooms[x][y] = dis;
                        q.push({x, y});
                    }
                }
            }
            
        }// queue is empty
    }
};


