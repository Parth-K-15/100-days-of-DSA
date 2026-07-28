You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999





// can't pass all test cases usinng greedy

// int minCostClimbingStairs(vector<int>& cost) {
//         int ans=0;
//         for(int i = cost.size(); i>1;){
//             if(cost[i-1]<cost[i-2]){
//                 ans+=cost[i-1];
//                 i--;
//             }
//             else{
//                 ans+=cost[i-2];
//                 i-=2;
//             }
//         }
//         return ans;
//     }




class Solution {
public:

    int count(int n, vector<int>& cost, vector<int>&dp){
        if(n<=1) return dp[n]=cost[n];
        if(dp[n] != -1) return dp[n];
        return dp[n] = cost[n] + min(count(n-1, cost, dp), count(n-2,cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int>dp(cost.size()+1,-1);
        return min(count(cost.size()-1,cost,dp), count(cost.size()-2,cost,dp));
        //to reach top we should be on either n-1 or n-2 th stair.
    }

};


  
