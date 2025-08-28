You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 




//not optimised (TC constraints)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, start = 0, end = k-1, a = INT_MIN;
        int n = nums.size();
        vector <int> ans;

        while(end < n){
            a = max(a,nums[i]);
            ++i;
            if(i>end){
                ans.push_back(a);
                end++;start++;i=start;
                a = INT_MIN;
            }
        }
        return ans;
    }
};



//Optimsed
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> de;
        vector<int> ans;
        for (int i = 0; i < k - 1; ++i) {
            while (!de.empty() && nums[i] > nums[de.back()]) {
                de.pop_back();
            }
            de.push_back(i);
        }
        for (int i = k-1; i < nums.size(); ++i) {
            if (!de.empty() && de.front() <= i - k) {
                de.pop_front();
            }
            while (!de.empty() && nums[i] > nums[de.back()]) {
                de.pop_back();
            }
            de.push_back(i);
            ans.push_back(nums[de.front()]);
        }
        return ans;
    }
};
