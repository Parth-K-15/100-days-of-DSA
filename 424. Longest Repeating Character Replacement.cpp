You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
  
Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.


  

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>v(26,0);
        int left = 0, result = 0, maxCount = 0;
        for (int i = 0; i<s.length();i++){
            v[s[i]-'A']++;
            maxCount = max(maxCount,v[s[i]-'A']);
            while (i-left+1 - maxCount > k){ //WindowSize - maxCount
                v[s[left]-'A']--;
                left++;
            }
            result = max(result,i-left+1);
        }
        return result;
    }
};
