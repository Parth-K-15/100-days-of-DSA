A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Return the of count how many possible ways the child can run up the stairs.

Examples:

Input: n = 3
Output: 4
Explanation: The following are 4 different ways
1 step + 1 step + 1 step 
1 step + 2 steps 
2 steps + 1 step 
3 steps
Input: n = 4
Output: 7
Explanation: Below are the 7 ways to reach 4th step:
1 step + 1 step + 1 step + 1 step
1 step + 2 steps + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 steps
2 steps + 2 steps
3 steps + 1 step
1 step + 3 steps
Input: n = 1
Output: 1
Constraints:
1 ≤ n ≤ 30








class Solution {
  public:
    int count(int n, vector<int>&dp){
        if(n==0) return dp[n] = 1;
        if(n<=2) return dp[n] = n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = count(n-1,dp) + count(n-2,dp) + count(n-3, dp);
    }
    
    int countWays(int n) {
        // your code here
        if(n<0) return 0;
        vector<int>dp(n+1,-1);
        return count(n,dp);
    }
};
