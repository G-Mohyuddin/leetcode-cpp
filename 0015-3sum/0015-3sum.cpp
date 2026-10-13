class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int size=nums.size();
        for(int i=0;i<size;++i){
            int k=size-1;
            int j=i+1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(j<k){
                if(nums[i]+nums[j]+nums[k]>0){
                    --k;
                    while(j<k && nums[k]==nums[k+1]){
                        --k;
                    }
                }else if(nums[i]+nums[j]+nums[k]<0){
                    ++j;
                    while(j<k && nums[j]==nums[j-1]){
                        ++j;
                    }
                }else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j-1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k+1]) {
                        --k;
                    }
                }
            }
        }
        return ans;
    }
};