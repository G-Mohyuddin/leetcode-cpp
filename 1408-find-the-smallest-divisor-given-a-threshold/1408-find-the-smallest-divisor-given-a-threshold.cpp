class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int size=nums.size();
        int start=1;
        int end = *max_element(nums.begin(),nums.end());
        while(start<=end){
            int sum=0;
            int mid=start+((end-start)/2);
            for(int i=0;i<size;++i){
                sum+=ceil(nums[i]/(double)mid);
            }
            if(sum<=threshold){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return start;
    }
};