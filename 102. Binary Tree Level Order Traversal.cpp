Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(!root) return vec;
        queue<TreeNode*> qe;
        qe.push(root);
        
        while(!qe.empty()){
            int size = qe.size();
            vector<int> level={};
            for (int i = 0; i<size; ++i){
                TreeNode* temp = qe.front();
                qe.pop();
                level.push_back(temp->val);
                if(temp -> left) qe.push(temp->left);
                if(temp -> right) qe.push(temp->right);
            }
            vec.push_back(level);
        }
        return vec;
    }
};
