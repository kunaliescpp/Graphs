/*
Problem Link: https://leetcode.com/problems/k-similar-strings/

K-Similar Strings

Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times 
so that the resulting string equals s2.
Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.

Example 1:
Input: s1 = "ab", s2 = "ba"
Output: 1

Example 2:
Input: s1 = "abc", s2 = "bca"
Output: 2
 

Constraints:
1 <= s1.length <= 20
s2.length == s1.length
s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
s2 is an anagram of s1.
*/

class Solution {
public: 
    
    //Time complexity : O(V+E) * O(n)  where V = n! (tree like structure formed)
    int kSimilarity(string s1, string s2){
        
        int n = s1.size();
        
        queue<string> q;
        int cnt = 0;
        q.push(s1);
        while(!q.empty()){
            
            int k = q.size();
            while(k--){
            string f = q.front(); q.pop();
            if(f == s2) return cnt;
            
            //all char is not at correct pos
            for(int i = 0; i <= n-2; i++){
        
                if(f[i] != s2[i]){ 
                    for(int j = i+1; j < n; j++){
                        if(s2[i] == f[j]){
                            string temp = f;
                            swap(temp[i], temp[j]);
                            if(temp == s2) return cnt+1;      //optimization
                            q.push(temp);
                        } 
                    }
                break; // loop i break
                }
            }
        }
            cnt++;
        }
    return 0;
    }
};


