Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.
 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
  
Example 2:

Input: nums = [5], k = 9
Output: 0




Time Complexity → O(n2)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int start = 0, end = 0, ans = 0, n = nums.size();
        int sum = 0;
        while (start <= end && end < n){
            sum += nums[end];
            if (sum % k == 0){
                ans++;
            }
            if (end == n-1){
                end=start;start++;
                sum = 0;
            }
            end++;
        }
        return ans;
    }
};


Time Complexity → O(n)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        int PrefixSum = 0;
        unordered_map <int, int> m;
        m[0] = 1;
        for (int i = 0; i<n; ++i){
            PrefixSum += nums[i];
            int mod = (PrefixSum % k + k) % k; // Ensure mod is non-negative
            if (m.count(mod)) {
                ans += m[mod];
            }
            m[mod]++;
        }
        return ans;
    }
};
