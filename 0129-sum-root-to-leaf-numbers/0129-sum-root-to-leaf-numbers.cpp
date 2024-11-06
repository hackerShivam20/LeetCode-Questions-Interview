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

    void dfs(TreeNode* node, int& totalSum, int currentSum){
        if(!node) return;
        
        currentSum = currentSum*10 + node->val;
        
        if(!node->left && !node->right){
            totalSum += currentSum;
            return;
        }
        
        dfs(node->left, totalSum, currentSum);
        dfs(node->right, totalSum, currentSum);
    }

    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        int currentSum = 0;
        dfs(root, totalSum, currentSum);
        return totalSum;
    }
    
};