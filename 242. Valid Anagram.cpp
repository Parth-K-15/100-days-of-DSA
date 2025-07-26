Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:
Input: s = "anagram", t = "nagaram"

Output: true

Example 2:
Input: s = "rat", t = "car"

Output: false

  

// Sliding Window
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()) return false;
        unordered_map<char,int>m;
        for (int i = 0;i<s.length();i++){
            m[s[i]]++;
        }
        for (int i = 0;i<t.length();i++){
            if (!m.count(t[i]) || m[t[i]]==0) return false;
            m[t[i]]--;
        }
        return true;
    }
};


//Optimised
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector <int> v(26,0);
        for (char c:s){
            v[c-'a']++;
        }
        for (char d:t){
            v[d-'a']--;
            if(v[d-'a']==-1) return false;
        }
        return true;
    }
};
