class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int i=0;
        while(i<=r){
            if(nums[i]==0){
                int temp = nums[l];
                nums[l]=nums[i];
                nums[i]=temp;
                ++l;
            }else if(nums[i]==2){
                int temp = nums[r];
                nums[r]=nums[i];
                nums[i]=temp;
                --r;
                --i;
            }
            ++i;
        }
    }
};