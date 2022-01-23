/*
Problem Link: https://leetcode.com/problems/word-ladder/

Word Ladder

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words 
beginWord -> s1 -> s2 -> ... -> sk such that:
=> Every adjacent pair of words differs by a single letter.
=> Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList. 
=> sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation 
sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:
1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = wordList.size();
        
        unordered_set<string> s;
        for(int i = 0; i < n; i++){
            s.insert(wordList[i]);
        }
    
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while(!q.empty()){
            
            int k = q.size();
            while(k--){
                
                string f = q.front(); q.pop();
                if(f == endWord) return steps;

                for(int i = 0; i < f.size(); i++){
                    for(int j = 0; j < 26; j++){
                        string temp = f.substr(0, i) + (char)(j+'a') + f.substr(i+1);
                        if(s.count(temp) == 1){
                            s.erase(temp);
                            q.push(temp);
                        }
                    }
                }  
            }
            steps++;
        } 
    return 0;
    }
};


