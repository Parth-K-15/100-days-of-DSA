// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> m;  
        //sum,count
        int total = 0;
        m[0] = 1;
        int prefix_sum = 0;
        for (int i = 0; i<nums.size();++i){
            prefix_sum += nums[i];
            if (m.count(prefix_sum - k)){
                total += m[prefix_sum-k];
                m[prefix_sum]++;
            }
            else{
                m[prefix_sum] ++; 
                //(6,2) already present now encountered with 6 again but 6-k is not in map in this case we can't set count of 6 to 1, hence use ++ -> (6,3)
            }
        }
        return total;
    }
};
