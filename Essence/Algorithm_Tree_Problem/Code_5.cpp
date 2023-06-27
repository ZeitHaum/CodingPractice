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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //declearation of dfs.
        function<void(int,int,int,int,TreeNode*)> dfs_build = [&](int ibegin,int iend,int pbegin,int pend,TreeNode* root){
            int i_ind = f[root->val];
            int left_len = i_ind-1 - ibegin + 1;
            int right_len = iend-1 - (i_ind+1) + 1;
            if(left_len!=0){
                TreeNode* left = new TreeNode(postorder[pbegin+left_len-1]);
                root->left = left;
                dfs_build(ibegin,i_ind,pbegin,pbegin+left_len,left);
            }
            if(right_len!=0){
                TreeNode* right = new TreeNode(postorder[pend-2]);
                root->right = right;
                dfs_build(i_ind+1, iend,pbegin+left_len,pend-1,right);
            }
        }; 
        //initialize of attributes.
        n = inorder.size();
        f.clear();
        map<int,int>g;
        for(int i = 0;i<n;i++){
            g[inorder[i]] = i;
        }
        for(int i = 0;i<n;i++){
            f[postorder[i]] = g[postorder[i]];
        }
        //calc ans.
        TreeNode* root = new TreeNode(postorder[n-1]);
        dfs_build(0,n,0,n,root);
        return root;
    }
};