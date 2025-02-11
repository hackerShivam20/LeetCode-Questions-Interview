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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val); // Create a new node if tree is empty

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val); // Insert in left subtree
        } else {
            root->right = insertIntoBST(root->right, val); // Insert in right subtree
        }
        
        return root; // Return the modified tree
    }
};