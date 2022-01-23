/*
Problem Link: https://leetcode.com/problems/regions-cut-by-slashes/

Regions Cut By Slashes

An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters 
divide the square into contiguous regions. Given the grid grid represented as a string array, return the number of regions.
Note that backslash characters are escaped, so a '\' is represented as '\\'.

Example 1:
Input: grid = [" /","/ "]
Output: 2

Example 2:
Input: grid = [" /","  "]
Output: 1

Example 3:
Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
 

Constraints:
n == grid.length == grid[i].length
1 <= n <= 30
grid[i][j] is either '/', '\', or ' '.
*/

class Solution {
public:
    int findpar(int u, vector<int>& parent){
        if(parent[u] == u) return u;

        int temp = findpar(parent[u], parent);
        parent[u] = temp;

    return temp;
    }
    
    void Union(int a, int b, vector<int>& parent, vector<int>& rank){
        
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
        }
       // else nothing todo
      
    }
    
    int regionsBySlashes(vector<string>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
     
    	vector<int> parent((m+1)*(m+1), 0);
        vector<int> rank((m+1)*(m+1));
        for(int i = 1; i < (m+1)*(m+1); i++){
        	parent[i] = i;
            rank[i] = 1;
        }
        
        for(int i = 0; i < m+1; i++){
            Union(0, i, parent, rank);              // 0th row-> 0, (0, 1, 2, 3)
            Union(0, (m+1)*i, parent, rank);        // 0th col-> 0, (0, 4, 8, 12)
            Union(0,  m*(m+1)+i, parent, rank);     // mth row-> 0, (4*3+i)
            Union(0, (m+1)*(i)+m, parent, rank);    // mth col-> 0, (4i+3)
        }
        
        
        int cnt = 1;  //by boundary
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    int posB = (i)*(m+1) + j+1;                     // (0, 4, 8) + j+1    -> ep
                    int posA = (i+1)*(m+1) + j;                     // (4, 8, 12) + j     -> sp
                    if(findpar(posA, parent) == findpar(posB, parent)) cnt++;
                    else Union(posA, posB, parent, rank);
                }
                
                else if(grid[i][j] == '\\'){
                    int posA = (i)*(m+1) + j;                     // (0, 4, 8) +  j        -> ep
                    int posB = (i+1)*(m+1) + j+1;                 // (4, 8, 12) + j+1      -> sp
                    if(findpar(posA, parent) == findpar(posB, parent)) cnt++;  
                    else Union(posA, posB, parent, rank);
                }
            }
        }
    return cnt;
    }
};


