Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
 

Follow up: Could you solve it with time complexity O(height of tree)?









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
    TreeNode* deleteN(TreeNode* root, int key){
        if(!root) return nullptr;
        if(root->val < key) root->right = deleteN(root->right, key);
        if(root->val > key) root->left = deleteN(root->left, key);
        if(root->val == key){
            // deleting leaf node
            if(!root-> left && !root->right){
                delete root;
                return nullptr;
            }

            // if root has one child 
            if(!root->left && root ->right){
                TreeNode* child = root -> right;
                delete root;
                return child;
            } 
            else if(root->left && !root ->right){
                TreeNode* child = root -> left;
                delete root;
                return child;
            } 
            
            // if root has 2 children
            if (root->left && root->right){
                TreeNode* parent=root;
                TreeNode* child=root->left;
                while(child->right){
                    parent = child;
                    child = child ->right;
                }
                // both parent child are diff
                if(parent != root){
                    TreeNode* childleft = child ->left;
                    parent -> right = childleft;
                    child -> left = root->left;
                    child -> right = root->right;
                    delete root;
                    return child;
                }
                // both parent and root are same
                if(parent == root){
                    // TreeNode* childleft = child ->left;
                    child -> right = root->right;
                    delete root;
                    return child;
                }
            }            
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteN(root,key);
    }
};
