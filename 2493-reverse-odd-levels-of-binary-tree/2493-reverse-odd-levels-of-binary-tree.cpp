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
    TreeNode* reverseOddLevels(TreeNode* root){
        queue<TreeNode*> q;
        int cnt = 0;
        q.push(root);

        while(!q.empty()){
            vector<TreeNode*> level;

            int n = q.size();

            for(int i=0;i<n;i++){
                TreeNode* ele = q.front();
                q.pop();
                level.push_back(ele);

                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);
            }
            if(cnt%2 != 0){
                int n = level.size();
                for(int i=0;i<n/2;i++){
                    swap(level[i]->val, level[n-i-1]->val);
                }
            }
            cnt++;
        }
        return root;
    }
};