class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size=nums.size();
        int negp=1;
        int posp=0;
        vector<int> ans(size);
        for(int i=0;i<size;++i){
            if(nums[i]<0 && negp<size){
                ans[negp]=nums[i];
                negp+=2;
            }else if(nums[i]>0 && posp<size){
                ans[posp]=nums[i];
                posp+=2;
            }
        }
        return ans;
    }
};