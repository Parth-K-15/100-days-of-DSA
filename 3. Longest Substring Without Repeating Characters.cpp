Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.




// Both solutions are accepted but this solution takes O(k) space complexity
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> m;
        for (int i = 0; i<s.size();++i) m[s[i]] = -1;
        int start = 0, end = 0, ans = 0, n = s.size(), var = 0;
        while (end < n){
            m[s[end]]++;
            if (m[s[end]] > 0){
                var ++;
            }
            while(var>0 && start <= end){
                m[s[start]] --;
                if (m[s[start]] == 0) var--; 
                start++;
            }
            if ((!var && start <= end) && (ans < end -start+1)){ //var == 0
                ans = end - start + 1;
            }
            if (!var && start <= end){ //var == 0
                ans = max(ans, end - start + 1);
            }
            end ++;
        }
        return ans; 
    }
};





class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <bool> m(256,0); //256 ascii char
        int start = 0, end = 0, ans = 0, n = s.size();
        while (end < n){
            while(m[s[end]]) m[s[start++]] = 0;
            ans = max(ans, end-start+1);
            m[s[end++]] = 1;
        }
        return ans; 
    }
};
