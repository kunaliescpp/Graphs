/*
Problem Link: https://leetcode.com/problems/similar-string-groups/

Similar String Groups

Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings 
X and Y are similar if they are equal. For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" 
and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".
Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts"
are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only 
if it is similar to at least one other word in the group.
We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

Example 1:
Input: strs = ["tars","rats","arts","star"]
Output: 2

Example 2:
Input: strs = ["omv","ovm"]
Output: 1
 
 
Constraints:
1 <= strs.length <= 300
1 <= strs[i].length <= 300
strs[i] consists of lowercase letters only.
All words in strs have the same length and are anagrams of each other.
*/

class Solution {
public:
    
    int findpar(int u, vector<int>& parent){
        if(parent[u] == u) return u;

        int temp = findpar(parent[u], parent);
        parent[u] = temp;

    return temp;
    }
    
    bool isSimilar(string s1, string s2){
        
        int cnt = 0; 
        for(int i = 0; i < s1.size(); i++){
            
            if(s1[i] != s2[i]) cnt++;
            
            if(cnt > 2) return false;
        }
    return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        int groups = n;
                   
        vector<int> parent(n+1, 0);
        for(int i = 1; i < n; i++){
            parent[i] = i;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                
                if(isSimilar(strs[i], strs[j]) == true){
        
                    int p1 = findpar(i, parent);
                    int p2 = findpar(j, parent);
                    if(p1 != p2){
                        parent[p2] = p1;
                        groups--;
                    }  
                } // same string loop ends 
            }
        }
    return groups;  
    }
};


