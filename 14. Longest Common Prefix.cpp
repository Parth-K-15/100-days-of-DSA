Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.




class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string s = strs[0]; 

        for (int i = 1; i < strs.size(); ++i) {
            int j=0;
            while(j<s.length() && j<strs[i].length() && s[j]==strs[i][j]){
                j++;
            }
            s.erase(j);
        }
        
        return s;
    }
};
