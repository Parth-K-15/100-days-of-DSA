Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.





class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.length();
        int mainLen = haystack.length();
        if (mainLen < len) return -1;
        int left = 0, right = len-1;
        while (right < mainLen){
            int temp = left;
            int i = 0;
            while (i<len && haystack[temp] == needle[i]){
                temp++;i++;
            }
            if(i==len) return left;
            left++;right++;
        }
        return -1;
    }
};
