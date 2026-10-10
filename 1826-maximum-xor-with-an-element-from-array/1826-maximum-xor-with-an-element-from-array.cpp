class Solution {
public:
    struct trie_node{
        trie_node* left;
        trie_node* right;
        trie_node() : left(NULL), right(NULL) {}
    };
    struct trie_node* root=NULL;
    static bool sort_by_mi(const pair<int,pair<int,int>>& a,const pair<int,pair<int,int>>& b){
        return a.second.second < b.second.second;
    }
    static bool sort_by_index(const pair<int,pair<int,int>>& a,const pair<int,pair<int,int>>& b){
        return a.first < b.first;
    }
    void insert(trie_node* root,int num){
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
    int maxXOR(trie_node* root,int num){
        int ans=0;
        trie_node* temp=root;
        if(!root->left && !root->right){return -1;}
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        root = new trie_node();
        sort(nums.begin(),nums.end());
        int q_size=queries.size();
        vector<int> ans(q_size);
        vector<pair<int,pair<int,int>>> off_q(q_size);
        for(int i=0;i<q_size;++i){
            off_q[i].first=i;
            off_q[i].second.first=queries[i][0];
            off_q[i].second.second=queries[i][1];
        }
        sort(off_q.begin(),off_q.end(),sort_by_mi);
        int size=nums.size();
        int j=0;
        int i=0;
        while(j<q_size){
            while(i<size && nums[i]<=off_q[j].second.second){
                insert(root,nums[i]);
                i++;
            }
            ans[off_q[j].first]=maxXOR(root,off_q[j].second.first);
            j++;
        }
        return ans;
    }
};