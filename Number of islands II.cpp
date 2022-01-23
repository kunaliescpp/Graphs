/* 
Problem Link: https://www.lintcode.com/problem/434/

Number of Islands II

Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally, the 2D matrix is all 0 
which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means
that you can change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each 
operator.You need to return an array of size K. 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent,
we consider them in the same island. We only consider up/down/left/right adjacent.

Examples: 
Example 1:
Input: n = 4, m = 5, A = [[1,1],[0,1],[3,3],[3,4]]
Output: [1,1,2,2]
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011
    
Example 2:
Input: n = 3, m = 3, A = [[0,0],[0,1],[2,2],[2,1]]
Output: [1,1,2,2]

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
   
    int find(int x, vector<int>& par){
        if(par[x] == x) return x;

        int temp = find(par[x], par);
        par[x] = temp;
    return temp;
    }
    
    vector<int> numIslands2(int m, int n, vector<Point> &operators) {
        
        vector<int> v;
        vector<vector<int>> dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

        vector<int> par(m*n, -1);
        vector<int> rank(m*n);
        int cnt = 0;
        for(auto p : operators){
            
            int row = p.x;
            int col = p.y;
            int cellnum = row*n + col;
            if(par[cellnum] != -1){     // handle duplicacy of point
                v.push_back(cnt);
                continue;
            }
            par[cellnum] = cellnum;
            rank[cellnum] = 1;
            cnt++;

            for(auto dx : dirs){
                int rowdash = row + dx[0];
                int coldash = col + dx[1];
                int celldash = rowdash*n + coldash;

                if(rowdash < 0 || coldash < 0 || rowdash >= m || coldash >= n || par[celldash] == -1) continue;

                // union (if neighbour is 1)
                int x_rep = find(cellnum, par);
                int y_rep = find(celldash, par);
                if(x_rep != y_rep){
                    if(rank[x_rep] > rank[y_rep]){
                        par[y_rep] = x_rep;
                    }
                    else if(rank[x_rep] < rank[y_rep]){
                        par[x_rep] = y_rep;
                    }
                    else{
                        par[y_rep] = x_rep;
                        rank[x_rep]++;
                    }
                    cnt--;
                }
            } // check neighbours ends
        v.push_back(cnt);
        } // iterating over list ends
    return v;
    } //function ends
};


