/*
Problem Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

Most Stones Removed 

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest
possible number of stones that can be removed.

Example 1:
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

Example 2:
Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

Example 3:
Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 

Constraints:
1 <= stones.length <= 1000
0 <= xi, yi <= 10^4
*/

class Solution {
public:
    
    int findpar(int u, unordered_map<int, int>& parent){
        if(parent[u] == u) return u;

        int temp = findpar(parent[u], parent);
        parent[u] = temp;

    return temp;
    }

    void Union(int a, int b, unordered_map<int, int>& parent, unordered_map<int, int>& rank, int &set){
        
        int p1 = findpar(a, parent);
        int p2 = findpar(b, parent);
        
        if(p1 != p2){
            
            set--;
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
    }
    
    //Time Complexity : O(N * log(N)) 
	// Space Complexity : O(N)
    int removeStones(vector<vector<int>>& stones) {
        
        int m = stones.size();
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
       
        int set = 0;
        for(int i = 0; i < m; i++){
            int row = stones[i][0];
            int col = -stones[i][1]-1;
            
            if(parent.count(row) == 0){
                set++;
                parent[row] = row;
                rank[row] = 1;
            }
            
            if(parent.count(col) == 0){
                set++;
                parent[col] = col;
                rank[col] = 1;
            }
            
            Union(row, col, parent, rank, set);
        }
    
    return (m-set);
    }
};


