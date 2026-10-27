class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<size;++i){
            int extra = target - nums[i];
            if(m.find(extra)!=m.end()){
                return {m[extra],i};
            }
            m[nums[i]]=i;
        }
        return {-1,-1};
    }
};