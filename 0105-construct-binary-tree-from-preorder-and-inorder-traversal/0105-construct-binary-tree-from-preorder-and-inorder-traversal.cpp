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
    TreeNode* build(vector<int>& preorder,int pre_start,int pre_end,vector<int>& inorder,int in_start,int in_end,map<int,int>& in_map){
        if(pre_start>pre_end || in_start>in_end){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[pre_start]);
        int in_root=in_map[root->val];
        int nums_left=in_root-in_start;
        root->left=build(preorder,pre_start+1,pre_start+nums_left,inorder,in_start,in_root-1,in_map);
        root->right=build(preorder,pre_start+nums_left+1,pre_end,inorder,in_root+1,in_end,in_map);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int in_size=inorder.size();
        map<int,int> in_map;
        for(int i=0;i<in_size;++i){
            in_map[inorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,in_size-1,in_map);
    }
};