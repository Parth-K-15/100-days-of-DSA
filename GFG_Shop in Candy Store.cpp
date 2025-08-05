In a candy store, there are different types of candies available and arr[i] represent the price of  ith types of candies. You are now provided with an attractive offer.
For every candy you buy from the store and get k other candies ( all are different types ) for free. Now you have to answer two questions, what is the minimum and maximum amount of money you have to spend to buy all the  candies.
In both the cases you must utilize the offer i.e. you buy one candy and get k other candies for free.

Examples :

Input: arr[] = [3, 2, 1, 4], k = 2
Output: [3, 7]
Explanation: As according to the offer if you buy one candy you can take at most two more for free. So in the first case, you buy the candy worth 1 and takes candies worth 3 and 4 for free, also you need to buy candy worth 2. So min cost: 1+2 = 3. In the second case, you can buy the candy worth 4 and takes candies worth 1 and 2 for free, also you need to buy candy worth 3. So max cost: 3+4 = 7.
Input: arr[] = [3, 2, 1, 4, 5], k = 4
Output: [1, 5]
Explanation: For minimimum cost buy the candy with the cost 1 and get all the other candies for free. For maximum cost buy the candy with the cost 5 and get all other candies for free.




class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0, j = n-1, min = 0, max = 0;
        sort(arr.begin(),arr.end());
        while(i<=j){
            min += arr[i];
            i++;j-=k;
        }
        i = 0; j = n-1;
        while(i<=j){
            max += arr[j];
            j--;i+=k;
        }
        vector<int>ans={min,max};
        return ans;
    }
};
