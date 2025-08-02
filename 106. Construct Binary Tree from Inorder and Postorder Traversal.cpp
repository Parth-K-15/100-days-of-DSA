// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree./
Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int find(vector<int>& in, int inst, int inend, int target) {
        for (int i = inst; i <= inend; ++i) {
            if (in[i] == target) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* Tree_Post(vector<int>& in, vector<int>& pre, int inst, int inend,
                       int index) {
        if (inst > inend) return NULL;
        TreeNode* Node = new TreeNode(pre[index]);
        int pos = find(in, inst, inend, pre[index]);
        Node->left = Tree_Post(in, pre, inst, pos - 1, index - (inend-pos)-1);
        Node->right = Tree_Post(in, pre, pos + 1, inend, index-1);
        return Node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return Tree_Post(inorder, postorder, 0, inorder.size()-1,inorder.size()-1);
    }
};
