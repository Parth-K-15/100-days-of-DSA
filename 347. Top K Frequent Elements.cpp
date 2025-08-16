Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]




class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }
        vector<pair<int, int>> vp;
        for (auto it = m.begin(); it != m.end(); it++) {
            vp.push_back({it->second, it->first});
        }
        sort(vp.rbegin(), vp.rend());
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(vp[i].second);
        }
        return result;
    }
};
