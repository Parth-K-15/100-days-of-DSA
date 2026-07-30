The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
 

Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.



//Accepted but can be optimised
int find(int n, vector<int>&dp){
    if(n<=0) return 0;
    if(n==1) return dp[n] = n;
    if(dp[n]!=-1)  return dp[n];
    return dp[n] = find(n-1,dp) +  find(n-2,dp) + find(n-3,dp);
}

int tribonacci(int n) {
    vector<int>dp(n+1,-1);
    return find(n,dp);
}




// Space Optimised
class Solution {
public:
    int tribonacci(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        int prev3 = 0, prev2 = 0, prev = 1;
        int curr;
        for (int i = 2; i<=n;++i){
            curr = prev3+prev2+prev;
            prev3=prev2;
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
};
