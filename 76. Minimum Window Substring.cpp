Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.




  class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char,int> m;
        int start = 0, end = 0;
        int total = t.size();
        int ans = INT_MAX;
        int index = -1;
        for (int i = 0; i < t.size();++i){
            m[t[i]]++;
        }
        while(end<s.size()){
            m[s[end]]--;
            if (m[s[end]] >= 0){
                total--;
            }
            //DECREASE SIZE OF WINDOW
            while(!total && start<=end){
                if (ans > end-start+1){
                    ans = end-start+1;
                    index = start;
                }
                m[s[start]]++;
                if (m[s[start]] > 0){
                    total++;
                }
                start++;
            }
            end++;
        }
        return (index == -1) ? "" : s.substr(index, ans);
    }
};
