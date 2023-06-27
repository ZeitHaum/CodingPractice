/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<int,TreeNode*> fa;
        map<int,int> h;
        auto bfs = [&](){
            queue<TreeNode*> q;
            q.push(root);
            fa[root->val] = NULL;
            h[root->val] = 0;
            while(q.size()!=0){
                TreeNode* qf = q.front();
                q.pop();
                if(qf->left!=NULL){
                    fa[qf->left->val] = qf;
                    h[qf->left->val] = h[qf->val]+1;
                    q.push(qf->left);
                }
                if(qf->right!=NULL){
                    fa[qf->right->val] = qf;
                    h[qf->right->val] = h[qf->val]+1;
                    q.push(qf->right);
                }
            }
        };
        bfs();
        function<TreeNode*(TreeNode*,TreeNode*)> find_lca = [&](TreeNode*p ,TreeNode* q){
            if(p->val==q->val) return p;
            if(h[p->val]>h[q->val]) return find_lca(fa[p->val],q);
            else if(h[p->val]<h[q->val]) return find_lca(p,fa[q->val]);
            else return find_lca(fa[p->val],fa[q->val]);
        };
        return find_lca(p,q);
    }
};