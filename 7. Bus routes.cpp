/*
Problem Link: https://leetcode.com/problems/bus-routes/

Bus Routes

You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between 
bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

Example 1:
Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

Example 2:
Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
 
Constraints:

1 <= routes.length <= 500.
1 <= routes[i].length <= 105
All the values of routes[i] are unique.
sum(routes[i].length) <= 105
0 <= routes[i][j] < 106
0 <= source, target < 106
Accepted
64,360
Submissions
144,128
Seen this question in a real interview before?
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        int n = routes.size();
        unordered_map<int, vector<int>>mp;              // bus stop | vector (bus)
        for(int i = 0; i < n; i++){
            for(auto bs : routes[i]){                   // 1    |    0th
                mp[bs].push_back(i);
            }
        }
        
        unordered_map<int, bool> vbusStop;
        vector<bool> vBus(n, false);
        
        queue<pair<int, int>> q;                  // bus stop, cnt of bus changes till now
        q.push({source, 0});
        while(!q.empty()){
            
            int currNode = q.front().first;
            int currVal = q.front().second;
            if(currNode == target) return currVal;
            
            q.pop();
            vbusStop[currNode] = true;
            
            for(auto bn : mp[currNode]){
                // phle bhi kabhi baith chuka hu
                if(vBus[bn] == true) continue;
                
                // abhi tak nhi baitha
                for(auto nextNode : routes[bn]){
                    // bus routes ki list me dekha ki ye bus kon si nyi jagah le jayegi 
                    if(vbusStop.count(nextNode) == 0) q.push({nextNode, currVal+1}); 
                }
            
                vBus[bn] = true;
            }   
        } 
    return -1;
    }
};


