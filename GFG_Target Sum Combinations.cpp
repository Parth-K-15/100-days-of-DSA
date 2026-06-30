Given an array arr[] of distinct integers and a target, your task is to find all unique combinations in the array where the sum is equal to target. The same number may be chosen from the array any number of times to make target.

Note: You can return your answer in any order, but the driver code will print the combinations in sorted order only.

Examples:

Input: arr[] = [1, 2, 3], target = 5
Output: [[1, 1, 1, 1, 1], [1, 1, 1, 2], [1, 1, 3], [1, 2, 2], [2, 3]]
Explanation: All the combination have sum of elements equals to target.
Input: arr[] = [2, 4], target = 1
Output: []
Explanation: No combination exits whose sum is equals to target.
Constraints:
1 ≤ arr.size() ≤ 30
1 ≤ arr[i] ≤ 40
1 ≤ target ≤ 40




class Solution {
  public:
    void Find(vector<int> &arr, int target, int n, int index, vector<int>&temp, vector<vector<int>>&ans){
        if (target == 0 && index == n){
            ans.push_back(temp);
            // return a;
        }
        if(index == n || target < 0) return;
        //nhi lena
        Find(arr, target,n,index+1,temp, ans);
        //lena
        temp.push_back(arr[index]);
        Find(arr, target-arr[index],n,index,temp, ans);
        temp.pop_back();
    }
    
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        vector<int> temp;
        vector<vector<int>> ans={};
        Find(arr,target, arr.size(), 0, temp, ans);
        return ans;
    }
};
