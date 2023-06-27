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
    bool ck = true;
    void dfs_symmetric(TreeNode* r1,TreeNode* r2){
        if(r1==nullptr || r2==nullptr){
            if(!(r1==nullptr && r2 == nullptr)) ck = false;
            return;
        }
        if(r1->val!=r2->val) ck = false;
        if(ck==false) return;
        dfs_symmetric(r1->left,r2->right);
        dfs_symmetric(r1->right,r2->left);
    }

    bool isSymmetric(TreeNode* root) {
        ck = true;
        if(root==nullptr) return ck;
        dfs_symmetric(root->left,root->right);
        return ck;
    }
};