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
    bool check = true;
    void dfs_same(TreeNode* r1,TreeNode* r2){
        if(check==false) return;
        if(r1==nullptr || r2==nullptr){
            if(!(r1 == nullptr && r2==nullptr)) check = false;
            return;
        }
        if(r1->val!=r2->val) check = false;
        dfs_same(r1->left,r2->left);
        dfs_same(r1->right,r2->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        check = true;
        dfs_same(p,q);
        return check;
    }
};