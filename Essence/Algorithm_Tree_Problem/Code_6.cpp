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
 //DP version
class Solution {
public:
    int ans = 0;
    int dfs_dp(TreeNode* root){
        if(root==nullptr) return 0;
        int h_l = dfs_dp(root->left);
        int h_r = dfs_dp(root->right);
        ans = max(ans,h_l+h_r);
        return max(h_l,h_r)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs_dp(root);
        return ans;
    }
};