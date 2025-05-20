// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]


class Solution {
public:
//issue: TC: (O(n^2))
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> answer (nums.size());
        for (int j = 0; j<nums.size();++j){
            int pro = 1;
            for (int i = 0; i< nums.size(); ++i){
                if (j != i){
                    pro = pro * nums[i];
                }
            }
            answer[j] = pro;
        }
        return answer;
    }
};





//Optimised
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans1(n,1);
        // vector <int> ans2(n,1);
        int prefix=1, suffix = 1;
        for (int i = 1; i < n; ++i){
            prefix *= nums[i-1];
            ans1[i]=prefix;
        }
        for (int i = n-2; i>=0; --i){
            suffix *= nums[i+1];
            // ans2[i]=suffix;
            ans1[i] = ans1[i] * suffix;
        }
        // vector <int> answer (n);
        // for (int i = 0; i<n;++i){
        //     answer[i] = ans1[i]*ans2[i];
        // }
        return ans1;
    }
};
