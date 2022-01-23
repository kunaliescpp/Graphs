/* 
Problem Link: https://leetcode.com/problems/satisfiability-of-equality-equations/

Satisfiability of Equality Equations

You are given an array of strings equations that represent relationships between variables where each string equations[i]
is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not 
necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

Example 1:
Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

Example 2:
Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 

Constraints:
1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] is a lowercase letter.
equations[i][1] is either '=' or '!'.
equations[i][2] is '='.
equations[i][3] is a lowercase letter.
*/

class Solution {
public:
    
    char findpar(char u, unordered_map<char, char>& parent){
        if(parent[u] == u) return u;

        char temp = findpar(parent[u], parent);
        parent[u] = temp;

    return temp;
    }

    void Union(char a, char b, unordered_map<char, char>& parent, unordered_map<char, int>& rank){
        
        char p1 = findpar(a, parent);
        char p2 = findpar(b, parent);

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
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        int m = equations.size();
      	unordered_map<char, char> parent;
        unordered_map<char, int> rank;
        for(int i = 0; i < 26; i++){
        	parent['a'+ i] = 'a'+i;
            rank['a'+ i] = 1;
        }
        
        for(int i = 0; i < m; i++){
            if(equations[i][1] == '='){
                Union(equations[i][0], equations[i][3], parent, rank);
            }
        }    
        
        for(int i = 0; i < m; i++){
            if(equations[i][1] == '!'){
                if(findpar(equations[i][0], parent) == findpar(equations[i][3], parent)) return false;
            } 
        }
    
    return true;
    }
};

  
  
