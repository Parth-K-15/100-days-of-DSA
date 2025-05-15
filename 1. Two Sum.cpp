// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Input: nums = [3,3], target = 6
// Output: [0,1]


// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Input: nums = [3,3], target = 6
// Output: [0,1]

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans(0);
        for (int i = 0; i<nums.size();++i){
            for (int j = i + 1; j < nums.size();++j){
                if (nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans(0);
        unordered_map <int,int> m;
        for (int i = 0; i < nums.size(); ++i){
            int complement = target - nums[i];
            if (m.find(complement) != m.end()){
                ans.push_back(m[complement]);
                ans.push_back(i);
                return ans;
            }
                m.insert({nums[i], i});
        }
        return {};
    }
};

//Time complexity - > O(1) on avg
//Space complexity -> O(n) worst case