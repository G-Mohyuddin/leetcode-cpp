class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        int ind=-1;
        for(int i=size-2;i>=0;--i){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=size-1;i>ind;--i){
            if(nums[ind]<nums[i]){
                int temp=nums[ind];
                nums[ind]=nums[i];
                nums[i]=temp;
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
    }
};