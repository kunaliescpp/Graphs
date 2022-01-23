/*
Problem Link: https://practice.geeksforgeeks.org/problems/minimum-swaps/1

Minimum Swaps to sort ans array

Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

Example 1:
Input: nums = {2, 8, 5, 4}
Output: 1
Explaination: swap 8 with 4.

Example 2:
Input: nums = {10, 19, 6, 3, 5}
Output: 2
Explaination: swap 10 with 3 and swap 19 with 5.


Constraints:
1 ≤ n ≤ 10^5
1 ≤ numsi ≤ 10^6
*/

class Solution{
    public:
    //Min. no. of swaps required to sort the array
    //Approach :  visualizing the problem as a graph. We will have n nodes and an edge directed 
    //from node i -> node j 
	int minSwaps(vector<int>&nums){
	    
	    int n = nums.size();
	    vector<pair<int, int>> v;             // value, curr idx
	    for(int i = 0; i < n; i++){
	        v.push_back({nums[i], i});
	    }
	    
	    sort(v.begin(), v.end());
	    
	    vector<bool> visited(n, false);
	    int cnt = 0;
	    for(int i = 0; i < n; i++){
	        if(visited[i] == true || v[i].second == i) continue;  // already tackle
	        
	        int clen = 0;  //cycle length
	        int j = i;
	        while(visited[j] == false){
	            visited[j] = true;
	            clen++;
	            j = v[j].second;
	        }
	        cnt += (clen-1);
	    }
	return cnt;   
	}
};


