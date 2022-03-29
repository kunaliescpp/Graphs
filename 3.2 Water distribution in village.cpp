/* 
Problem Link: https://www.codingninjas.com/codestudio/problems/water-supply-in-a-village_1380956

Water Supply In A Village

There are ‘N’ houses in a village. Ninja wants to supply water for all the houses by building wells and laying pipes.
For each house ‘i’, we can either build a well inside it directly with cost ‘WELLS[i]’, or pipe in water from another well to it.
The total cost to lay pipes between houses is given by the array ‘PIPES’, where ‘PIPES[i]’ = ‘[HOUSE1, HOUSE2, COST]’ and the ‘COST’
represent the total cost connect ‘HOUSE1’ and ‘HOUSE2’ together using a pipe.

Note: Given all the connections are bidirectional.
For Example: For ‘N’ = 3, ‘WELLS[]’ = ‘[1,2,2]’, ‘PIPES[]’ = [ [1, 2, 1], [2 , 3, 1]]. The image shows the costs of connecting houses 
using pipes. The best strategy is to build a well in the first house with cost 1 and connect the other houses to it with cost 2 so the 
total cost is 3.

Ninja wants to find out the minimum total cost to supply water to all houses in the village. Can you help the Ninja to find out this minimum cost?

Input Format
The first line of input contains an integer 'T' representing the number of test cases. Then the test cases follow.
The first line of each test case contains two integers ‘N’ and ‘K’ representing the number of Houses in the village and the size of ‘PIPES’
respectively.
The next line contains ‘N’ single space-separated integers denoting ‘WELLS[i]’.
The next ‘K’ line contains 3 single space-separated integers denoting ‘PIPES[i][0]’, ‘PIPES[i][1]’ and ‘PIPES[i][2]’.

Output Format :
For each test case, print the minimum cost to supply water to all the houses in the village. 
The output for each test case is printed in a separate line.


Constraints :
1 <= T <= 100
1 <= N <= 10 ^ 2
0 <= WELLS[i] <= 10^5
1 <= K <= 10000
1 <= PIPES[i][0], PIPES[i][1] <= N
0 <= PIPES[i][2] <= 10^5
PIPES[i][0] != PIPES[i][1]
Where ‘T’ is the number of test cases, ‘N’ is the number of houses in the village, WELL[i]’ denotes the cost of inserting a 
well at house ‘i’ and ‘PIPES[i][0]’, ‘PIPES[i][1]’ and ‘PIPES[2]’ represents the cost to connect house ‘PIPES[i][0]’ to ‘PIPES[i][1]’.

Time Limit: 1 sec
Sample Input 1 :
2
4 2
1 4 4 4
1 4 2
1 2 1
3 3
5 5 5
1 2 80
1 3 20
2 3 90
Sample Output 1:
8
15    
Explanation for Sample Output 1:
For the first test case :
The efficient way to supply water to all houses is to connect 0 with 1 and 0 with 2 and build a well at house 0 and 3. 
So the total cost will be 1 (well at house 0) + 4 (well at house 3) + 2 (connect 0 and 1) + 1 (connect 0 and 2) which is 8.

For the second test case :
The efficient way to supply water to all houses is to make well at all the houses. So the total cost will be 5 (well at house 0) 
+ 5 (well at house 1) + 5 (well at house 2) which is 15.

Sample Input 2 :
2
2 1
8 2
1 2 1
2 1
1 1
1 2 1
Sample Output 2 :
3
2

Explanation for Sample Output 2:
For the first test case: The efficient way to supply water to all houses is to connect 1 with 2 and build a well at house 1. So the 
total cost will be 2 (well at house 1) + 1 (connect 1 and 2) Which is equal to 3.

For the second test case :
The efficient way to supply water to all houses is to connect 1 with 2 or build well at both of the houses. The answer will be the same for either case. Which is equal to 2.
*/

//minimum spanning tree
// houses(n) = 4, digwell[4] = [1, 4, 4, 4]
// pipes data(k) = 2, pipesCost[2] = [1->4 = 2], [1->2 = 1]

#include <algorithm>

class node{
    public:
    int node1;
    int node2;
    int cost;

    node(int n1, int n2, int c){
        node1 = n1;
        node2 = n2;
        cost = c;
    }
};

int findpar(int u, vector<int>& parent){
    if(parent[u] == u) return u;

    int temp = findpar(parent[u], parent);
    parent[u] = temp;

return temp;
}

void Union(int a, int b, vector<int>& parent, vector<int>& rank){
 
    int p1 = findpar(a, parent);
    int p2 = findpar(b, parent);
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

static bool mycmp(node n1, node n2){
    return n1.cost < n2.cost;
}

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {

    vector<node> adj;   // 1 dummy node '0' also included
    // step 1
    for(int i = 0; i < k; i++){
        int u = pipes[i][0];
        int v = pipes[i][1];
        int wt = pipes[i][2];

        adj.push_back(node(u, v, wt));
    }
    
    for(int i = 1; i <= n; i++){
        adj.push_back(node(0, i, wells[i-1]));
    }

    sort(adj.begin(), adj.end(), mycmp);

    //Step 2
    vector<int> parent(n+1);
    vector<int> rank(n+1);
    for(int i = 0; i <= n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
    
    int minCost = 0;
    for (auto x : adj) {
        if (findpar(x.node1, parent) == findpar(x.node2, parent)) continue;
      
        minCost += x.cost;
        Union(x.node1, x.node2, parent, rank);
        // For each union, we connnect one node.
        n--;
        // If all nodes already connected, terminate early.
        if (n == 0) return minCost;
    }

return minCost;
}


