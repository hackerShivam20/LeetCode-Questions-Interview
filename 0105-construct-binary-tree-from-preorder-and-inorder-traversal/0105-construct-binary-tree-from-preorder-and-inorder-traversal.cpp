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
    TreeNode* bt(vector<int>& inorder, int ins, int ine, vector<int>& preorder, int prs, int pre, map<int,int>& mp){
        if(ins > ine || prs > pre){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prs]);

        int inroot = mp[root->val];

        int lefty = inroot - ins;

        root -> left = bt(inorder, ins, inroot-1, preorder, prs+1, prs + lefty, mp);

        root -> right = bt(inorder, inroot + 1, ine, preorder, prs + lefty + 1, pre, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;

        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        return bt(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, mp);
    }
};