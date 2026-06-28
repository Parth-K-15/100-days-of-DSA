Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8


class Solution {
public:
    void GenFun(int n, vector<string>&ans, string &temp, int left, int right){
        if(left + right == 2*n) {
            ans.push_back(temp);
            return;
        }
        if(left < n) {
            temp.push_back('(');
            GenFun(n,ans,temp,left+1,right);
            temp.pop_back();
        }
        if(right<left){
            temp+=')';
            GenFun(n,ans,temp,left,right+1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        GenFun(n,ans,temp,0,0);
        return ans;
    }
};
