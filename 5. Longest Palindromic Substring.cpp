Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"



class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, end = 0;
        for (int i = 0; i<s.length();++i){
            //odd Length
            int left = i, right = i;
            while(left>=0 && right < s.length() && s[left] == s[right]){
                --left;++right;
            }
            int len1 = right-left-1;

            //even Length
            left = i, right = i+1;
            while(left>=0 && right < s.length() && s[left] == s[right]){
                --left;++right;
            }
            int len2 = right-left-1;

            int len = max(len1,len2);
            if (len>end-start){
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start,end-start+1);
    }
};
