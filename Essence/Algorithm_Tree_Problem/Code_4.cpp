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
    int n;
    map<int,int>f;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        function<void(int,int,int,int,TreeNode*)> dfs_build = [&](int pbegin,int pend,int ibegin,int iend,TreeNode* root){
            //左闭右开 
            int i_ind = f[root->val];
            int left_len = i_ind-1 - ibegin + 1;
            int right_len = iend-1 - (i_ind+1) + 1;
            if(left_len!=0){
                int root_val = preorder[pbegin+1];
                TreeNode* left = new TreeNode(root_val);
                root->left = left;
                dfs_build(pbegin+1,pbegin+1+left_len,ibegin,i_ind,left);
            }
            if(right_len!=0){
                int root_val = preorder[pbegin+1+left_len];
                TreeNode* right = new TreeNode(root_val);
                root->right = right;
                dfs_build(pbegin+1+left_len,pend,i_ind+1,iend,right);
            }
        };
        n = preorder.size();
        f.clear();
        map<int,int>g;
        for(int i = 0;i<n;i++){
            g[inorder[i]] = i;
        }    
        for(int i = 0;i<n;i++){
            f[preorder[i]] = g[preorder[i]];
        }
        TreeNode* root = new TreeNode(preorder[0]);
        dfs_build(0,n,0,n,root);
        return root;
    }
};