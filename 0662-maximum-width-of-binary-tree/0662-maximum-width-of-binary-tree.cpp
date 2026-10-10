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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long int>> q;
        long long int ans=0;
        if(!root){return 0;}
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long int first,last;
            long long int tmin=q.front().second;
            for(int i=0;i<size;++i){
                long long int cur_id = q.front().second - tmin;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i==0){
                    first=cur_id;
                }
                if(i==size-1){
                    last=cur_id;
                }
                if(temp->left){
                    q.push({temp->left,2*cur_id+1});
                }
                if(temp->right){
                    q.push({temp->right,2*cur_id+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return (int)ans;
    }
};