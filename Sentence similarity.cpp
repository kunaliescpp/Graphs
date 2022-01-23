/*
Problem Link: https://www.lintcode.com/problem/855/

Sentence Similarity II

Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two 
sentences are similar. For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the 
similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]]. 

Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then 
"great" and "fine" are similar. Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great"
being similar. Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] 
are similar, even though there are no specified similar word pairs. Finally, sentences can only be similar if they have the same number of
words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

1.The length of words1 and words2 will not exceed 1000.
2.The length of pairs will not exceed 2000.
3.The length of each pairs[i] will be 2.
4.The length of each words[i] and pairs[i][j] will be in the range [1, 20].

Example 1: 
Input: ["great","acting","skills"] 
       ["fine","drama","talent"] 
       [["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]
Output: true
*/

class Solution {
public:
    
    string findpar(string u, unordered_map<string, string>& parent){
        if(parent[u] == u) return u;

        string temp = findpar(parent[u], parent);
        parent[u] = temp;

    return temp;
    }

    void Union(string a, string b, unordered_map<string, string>& parent){

        string p1 = findpar(a, parent);
        string p2 = findpar(b, parent);
    
        if(p1 != p2){
            parent[p2] = p1;
        }  
    }

    bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        
        int m = pairs.size();
        if(m == 0) return true;
        int n = pairs[0].size();

        if(words1.size() != words2.size()) return false;

        unordered_map<string, string> parent;
        int cnt = 0;
        for(int i = 0; i < m; i++){
            string f = pairs[i][0];
            string s = pairs[i][1];

            if(parent.count(f) == 0) parent[f] = f;
                
            if(parent.count(s) == 0) parent[s] = s;
                
            Union(f, s, parent);
        }

        for(int i = 0; i < words1.size(); i++){
            if(parent.count(words1[i]) != parent.count(words2[i])) return false;
        }
    
    return true;
    }
};


