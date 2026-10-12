class Solution {
public:
    int bs(vector<int>& nums,int start,int end,int size){
        int mid=start+((end-start)/2);
        if(mid==0 && nums[mid]>nums[mid+1]){
            return mid;
        }else if(mid ==0 && nums[mid]<nums[mid+1]){
            return mid+1;
        }
        if(mid==size-1 && nums[mid]>nums[mid-1]){
            return mid;
        }else if(mid==size-1 && nums[mid]<nums[mid+1]){
            return mid-1;
        }
        if(nums[mid]<nums[mid-1]){
            return bs(nums,start,mid-1,size);
        }else if(nums[mid]<nums[mid+1]){
            return bs(nums,mid+1,end,size);
        }else{
            return mid;
        }
        
        return 0;
    }
    int findPeakElement(vector<int>& nums) {
        int size=nums.size();
        if(size==0){return -1;}
        if(size==1){return 0;}
        return bs(nums,0,nums.size()-1,size);
    }
};