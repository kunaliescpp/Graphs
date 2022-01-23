/*
Problem Link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

Job Sequencing Problem 

Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and 
only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.
Note: Jobs will be given in the form (Job_id, Deadline, Profit) associated with that Job.

Example 1:

Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output: 2 60
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

Example 2:
Input: N = 5, Jobs = {(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}
Output: 2 127
Explanation: 2 jobs can be done with maximum profit of 127 (100+27).


Constraints:
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500
*/

#include<bits/stdc++.h>
using namespace std; 

struct Job{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution {
    public:
    // find parent & Union
    int findpar(int u, vector<int>& parent){
        if(parent[u] == u) return u;

        int temp = findpar(parent[u], parent);
        parent[u] = temp;

    return temp;
    }
    
    void Union(int a, int b, vector<int>& parent){
    
        int p1 = findpar(a, parent);
        int p2 = findpar(b, parent);
            
        if(p1 != p2){
            parent[p2] = p1;
        } 
    } 
    
    // sort profit-wise
    static bool mycmp(Job a, Job b){
        
        if(a.profit < b.profit) return false;
        
    return a.profit > b.profit;
    }
    
    //find the maximum profit and the number of jobs done.
    // Time complexity : O(n*log n) + O(n) + O(n* log(maxDeadline)
    vector<int> JobScheduling(Job arr[], int n){ 
        
        sort(arr, arr+n, mycmp);
        
        int maxDeadline = INT_MIN;
        for(int i = 0; i < n; i++){
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        vector<int> parent(maxDeadline+1);
        for(int i = 0; i <= maxDeadline; i++){
            parent[i] = i; 
        }
    
        int cnt = 0, max_profit = 0;
        for(int i = 0; i < n; i++){
            int currPar = findpar(arr[i].dead, parent);
            if(currPar == 0) continue;
            
            max_profit += arr[i].profit;
            Union(findpar(currPar-1, parent), currPar, parent);
            cnt++;
        }

        // Return in vector form
        vector<int> v;
        v.push_back(cnt);
        v.push_back(max_profit);
    
    return v;
    } 
};


