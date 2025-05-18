// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.



class Solution {
public:
//Brute Force (issue: TC: O(n^2))
    int maxProfit(vector<int>& prices) {
        map <int, unordered_map<int,int>> m;
        m[0].insert({0,0});
        for (int i = 0; i< prices.size(); ++i){
            for (int j = i+1; j<prices.size();++j){
                if (prices[j]-prices[i]>m.rbegin()->first){
                    m[prices[j]-prices[i]].insert({prices[j],prices[i]});
                }
            }
        }
        int profit = m.rbegin()->first;
        return profit;
    }
};






class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int MaxProfit = 0;
        for (int iter:prices){
            minVal = min(minVal,iter);
            MaxProfit = max(MaxProfit, iter-minVal);
        }
        return MaxProfit;
    }
};
