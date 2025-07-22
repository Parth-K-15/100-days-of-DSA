Given a string str, your task is to find the length of the smallest window that contains all the characters of the given string at least once.

Example:

Input: str = "aabcbcdbca"
Output: 4
Explanation: Sub-String "dbca" has the smallest length that contains all the characters of str.
Input: str = "aaab"
Output: 2
Explanation: Sub-String "ab" has the smallest length that contains all the characters of str.
Input: str = "geeksforgeeks"
Output: 7
Explanation: There are multiple substring with smallest length that contains all characters of str, "eksforg" and "ksforge". 



class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_map<char, int> m;
        string s = str;
        int n = s.length(), length = INT_MAX;
        int start = 0, end = 0, index = -1, total = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (!m[s[i]]) {
                m[s[i]] = 1;
                total++;
            }
        }
        while (end < n) {
            m[s[end]]--;
            if (m[s[end]] == 0) total--;
            while(!total && start<=end){
                if (length>end-start+1){
                    length = end-start+1;
                    index = start;
                }
                m[s[start]]++;
                if (m[s[start]]>0) total ++;
                start++;
            }
            end++;
        }
        return length;
    }
};
