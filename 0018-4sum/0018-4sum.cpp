class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<size;++i){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<size;++j){
                int k=j+1;
                int l=size-1;
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                while(k<l){
                    if((long long)nums[i]+nums[j]+nums[k]+nums[l]>target){
                        l--;
                        while(k<l && nums[l]==nums[l+1]){
                            l--;
                        }
                    }else if((long long)nums[i]+nums[j]+nums[k]+nums[l]<target){
                        k++;
                        while(k<l && nums[k]==nums[k-1]){
                            k++;
                        }
                    }else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        l--;
                        while(k<l && nums[l]==nums[l+1]){
                            l--;
                        }
                        k++;
                        while(k<l && nums[k]==nums[k-1]){
                            k++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};