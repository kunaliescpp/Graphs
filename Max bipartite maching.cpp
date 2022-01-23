/*
Problem Link: https://practice.geeksforgeeks.org/problems/maximum-bipartite-matching/1/

Maximum Bipartite Matching 

There are M job applicants and N jobs.  Each applicant has a subset of jobs that he/she is interseted in. Each job opening 
can only accept one applicant and a job applicant can be appointed for only one job. Given a matrix G where G(i,j) denotes 
ith applicant is interested in jth job. Find an assignment of jobs to applicant in such that as many applicants as possible get jobs.
 
Example 1:
Input: G = {{1,1,0,1,1},{0,1,0,0,1},{1,1,0,1,1}}
Output: 3
Explanation: There is one of the possible assignment- First applicant gets the 1st job, Second applicant gets the 2nd job, 
Third applicant gets the 3rd job.

Example 2:
Input: G = {{1,1},{0,1},{0,1},{0,1},{0,1},{1,0}}
Output: 2
Explanation: There is one of the possible assignment- First applicant gets the 1st job, Second applicant gets the 2nd job.
 
 
Constraints:
1 ≤ N, M ≤ 100
*/

class Solution{
public:

// m = poople, n = jobs
int maximumMatch(vector<vector<int>>& adj){

    int m = adj.size();
    int n = adj[0].size();
    int ans = 0;
    int src = 0, dest = m-1;

    while(true){
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(src);
        parent[src] = src;
        //step 1-> check if path exist
        while(!q.empty()){
            int u = q.front(); q.pop();

            for(int u = 0; u < m; u++){
                for(int v = 0; v < n; v++){
                    if(adj[u][v] == 0 || parent[v] != -1) continue;
                    parent[v] = u;
                    q.push(v);
                }
            }
        } // queue is empty()

        if(parent[dest] == -1) break;

        //step 2->finding amount of water we can flow at an instant
        int mini = INT_MAX;
        for(int v = dest; v != src; v = parent[v]){
            int u = parent[v];
            mini = min(mini, adj[u][v]);
        }

        //step 3->flowing water in the given street and putting back-edge
        for(int v = dest; v != src; v = parent[v]){
            int u = parent[v];
            adj[u][v] -= mini; 
            adj[v][u] += mini; // back-edge
        }
        ans += mini;
    }
return ans;
}

  
