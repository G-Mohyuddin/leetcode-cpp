class Solution {
public:
    struct trie_node{
        trie_node* left;
        trie_node* right;
        trie_node() : left(NULL), right(NULL) {}
    };
    void insert(trie_node* root,int& num){
        trie_node* temp=root;
        for(int i=31;i>=0;--i){
            int ith_bit=(num>>i)&1;
            if(ith_bit==0){
                if(temp->left==NULL){
                    temp->left=new trie_node();
                }
                temp=temp->left;
            }else{
                if(temp->right==NULL){
                    temp->right=new trie_node();
                }
                temp=temp->right;
            }
        }
    }
    int maxXOR(trie_node* root,int& num){
        int ans=0;
        trie_node* temp=root;
        for(int i=31;i>=0;--i){
            int ith_bit=(num>>i)&1;
            if(ith_bit==1){
                if(temp->left){
                    ans+=1<<i;
                    temp=temp->left;
                }else{
                    temp=temp->right;
                }
            }else{
                if(temp->right){
                    ans+=1<<i;
                    temp=temp->right;
                }else{
                    temp=temp->left;
                }
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        trie_node* root = new trie_node();
        int size=nums.size();
        int ans=0;

        for(int& num : nums){
            insert(root,num);
        }

        for(int i=0;i<size;++i){
            int temp=maxXOR(root,nums[i]);
            ans=max(ans,temp);
        }
        return ans;
    }
};