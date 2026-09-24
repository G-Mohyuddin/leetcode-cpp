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
    int countNodes(TreeNode* root) {
        int lc=1,rc=1;
        TreeNode* temp=root,*temp2=root;
        if(temp==NULL){
            return 0;
        }
        while(temp->left!=NULL){
            lc++;
            temp=temp->left;
            
        }
        while(temp2->right!=NULL){
            rc++;
            temp2=temp2->right;
        }
        if(lc==rc){
            return pow(2,lc)-1;
        }else{
            return countNodes(root->left)+countNodes(root->right)+1;
        }
        return 0;
    }
};