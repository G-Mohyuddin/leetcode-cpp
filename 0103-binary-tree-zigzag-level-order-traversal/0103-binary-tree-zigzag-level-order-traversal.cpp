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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> queue;
        bool left_to_right=true;
        if(!root){
            return ans;
        }else{
            queue.push(root);
        }
        while(queue.size()>0){
            int size=queue.size();
            vector<int> temp(size);
            for(int i=0;i<size;++i){
                TreeNode* v=queue.front();
                queue.pop();
                int ind=left_to_right ? i : size-1-i; 
                temp[ind]=v->val;
                if(v->left){
                    queue.push(v->left);
                }
                if(v->right){
                    queue.push(v->right);
                }
            }
            ans.push_back(temp);
            left_to_right=!left_to_right;
        }
        return ans;
    }
};