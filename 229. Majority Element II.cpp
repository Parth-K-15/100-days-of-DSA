Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]




  class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int count = 1, n = nums.size();
        for (int i = 1;i<=n;i++){
            if (i<n && nums[i] == nums[i-1]){
                count++;
            }
            else{
                if (count > n/3 && find(ans.begin(),ans.end(),nums[i-1]) == ans.end() ){
                ans.push_back(nums[i-1]);
                }
                count = 1;
            }            
        }
        return ans;
    }
};
