Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.






class Solution {
public:
    void permutation(vector <int>&nums, vector <vector <int>>&ans, vector <int>&temp, vector <bool>&visited){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i<nums.size(); ++i){
            if(!visited[i]){
                visited[i]=1;
                temp.push_back(nums[i]);
                permutation(nums,ans,temp,visited);
                temp.pop_back();
                visited[i]=0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> ans;
        vector <int> temp;
        vector <bool> visited(nums.size(),false);
        permutation(nums,ans,temp,visited);
        return ans;
    }
};
