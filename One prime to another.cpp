/* 
Problem Link: https://www.spoj.com/problems/PPATH/

The ministers of the cabinet were quite upset by the message from the Chief of Security stating that they would all have to change the four-digit 
room numbers on their offices.
— It is a matter of security to change such things every now and then, to keep the enemy in the dark.
— But look, I have chosen my number 1033 for good reasons. I am the Prime minister, you know!
— I know, so therefore your new number 8179 is also a prime. You will just have to paste four new digits over the four old ones on your office door.
— No, it's not that simple. Suppose that I change the first digit to an 8, then the number will read 8033 which is not a prime!
— I see, being the prime minister you cannot stand having a non-prime number on your door even for a few seconds.
— Correct! So I must invent a scheme for going from 1033 to 8179 by a path of prime numbers where only one digit is changed from one prime to the next
  prime.

Now, the minister of finance, who had been eavesdropping, intervened.
— No unnecessary expenditure, please! I happen to know that the price of a digit is one pound.
— Hmm, in that case I need a computer program to minimize the cost. You don't know some very cheap software gurus, do you?
— In fact, I do. You see, there is this programming contest going on...

Help the prime minister to find the cheapest prime path between any two given four-digit primes! The first digit must be nonzero, of course. Here is 
a solution in the case above - 1033  1733  3733  3739  3779  8779  8179     
The cost of this solution is 6 pounds. Note that the digit 1 which got pasted over in step 2 can not be reused in the last step – a new 1 must be 
purchased.

Input
One line with a positive number: the number of test cases (at most 100). Then for each test case, one line with two numbers separated by a blank. 
Both numbers are four-digit primes (without leading zeros).

Output
One line for each case, either with a number stating the minimal cost or containing the word Impossible.

Example: 
Input:
3
1033 8179
1373 8017
1033 1033

Output:
6
7
0
*/

#include <bits/stdc++.h>
using namespace std;

//Time Complexity : O(N^2 * (log n))

// all 4 digits prime numbers
void sieveofEratosthenes(vector<bool> &isPrime, int n){
    
    isPrime[0] = false; isPrime[1] = false;
    for(int i = 2; i <= n; i++){

        if(isPrime[i] == true){
            for(int j = i*i; j <= n; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

int bfs(int num1, int num2){

    string a = to_string(num1);
    string b = to_string(num2);

    int n = 9999;
    vector<bool> isPrime(n+1, true);
    sieveofEratosthenes(isPrime, n);

    int cnt = 0;
    queue<string> q;
    q.push(a);
    while(!q.empty()){
        
        int k = q.size();
        while(k--){
            string curr = q.front(); q.pop();
            if(curr == b) return cnt;

            for(int i = 0; i < 4; i++){
                for(int j = 0; j <= 9; j++){
                    if(curr[i] == (char)(j+'0') || (i==0 && j==0)) continue;
                    string temp = curr;
                    temp[i] = (char)(j+'0');

                    if(isPrime[stoi(temp)] == true){
                        q.push(temp);
                        isPrime[stoi(temp)] = false;
                    }
                }
            }
        }
        cnt++;
    } //while loop ends
return cnt;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int num1, num2;
        cin >> num1 >> num2;
        // cout << num1 << " " << num2 << endl;
        cout << bfs(num1, num2) << endl;
    }

return 0;
}


