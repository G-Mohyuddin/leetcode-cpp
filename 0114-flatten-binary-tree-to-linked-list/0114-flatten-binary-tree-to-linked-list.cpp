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
    void rev_preorder(TreeNode *r,TreeNode *&p){
        if(r==NULL){return;}
        rev_preorder(r->right,p);
        rev_preorder(r->left,p);
        r->right=p;
        r->left=NULL;
        p = r;
    }
    void flatten(TreeNode* root) {
        TreeNode* p=NULL;
        rev_preorder(root,p);
    }
};