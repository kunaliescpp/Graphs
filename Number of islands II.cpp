/* 
Problem Link: https://www.lintcode.com/problem/804/

Number of Distinct Islands

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally
(horizontal or vertical). You may assume all four edges of the grid are surrounded by water. Count the number of distinct 
islands. An island is considered to be the same as another if and only if one island has the same shape as another island 
(and not rotated or reflected).

Note - The length of each dimension in the given grid does not exceed 50.

Examples: 
Example 1:
Input: [[1,1,0,0,1],[1,0,0,0,0],[1,1,0,0,1],[0,1,0,1,1]]
Output: 3
Explanation: The island is look like this:
              11000
              10000
              00001
              00011
Notice that 11  and  1 are considered same island shapes. Because if we make a 180 degrees clockwise rotation on the first 
            1       11 
island, then two islands will have the same shapes.
            
Example 2:
Input: [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
Output: 1
*/

class Solution {
public:

    static bool mycmp(pair<int, int>& a, pair<int, int>& b){
        
        if(a.second > b.second) return a.first > b.first;

    return a.first < b.first;
    }

    // (int, int)vector -> String
    string getStr(vector<pair<int, int>> p){
        
        sort(p.begin(), p.end(), mycmp);

        string str = "";
        int x = p[0].first;
        int y = p[0].second;
        for (pair<int, int> point : p){
            str += (to_string(point.first-x) + " " + to_string(point.second-y));
        }

    return str;
    }

    // src-right-down & src-down-right must be same and taken as unique
    string getUnique(vector<pair<int, int>> v){
        
        vector<string> sameIslands;
        
        int trans[4][4] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for(int i = 0; i < 4; i++){
            vector<pair<int, int>> p1;
            vector<pair<int, int>> p2;        
            for(pair<int, int> p: v){
                int x = p.first;
                int y = p.second;
                p1.push_back({x*trans[i][0], y*trans[i][1]});
                p2.push_back({y*trans[i][0], x*trans[i][1]});
            }
            sameIslands.push_back(getStr(p1));
            sameIslands.push_back(getStr(p2));
        }
        
        sort(sameIslands.begin(), sameIslands.end(), mycmp);

    return sameIslands[0];
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y, vector<pair<int, int>>& v){
        
        int m = grid.size();
        int n = grid[0].size();

        v.push_back({x, y});
        grid[x][y] = 0;

        int dx[4] = {0, -1, 1, 0};
        int dy[4] = {-1, 0, 0, 1};
        for(int i = 0; i < 4; i++){
            int nr = x + dx[i];
            int nc = y + dy[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc]==1){
                dfs(grid, nr, nc, v);
            }
        }
    }

    int numDistinctIslands2(vector<vector<int>> &grid){
    
        int m = grid.size();
        int n = grid[0].size();

        set<string> s;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){   
                    vector<pair<int, int>> v;    // v[x, y]
                    dfs(grid, i, j, v);
                    s.insert(getUnique(v));
                }
            }
        }
        
    return (int)s.size();
    }
};


