class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //if we subtract sum of the input vector from the sum of range [0,n] we will get the missing number.
        //to calc both sum in same loop as nums contain n numbers and the range has n+1 numbers, we initialize the range sum with the size of nums as range is [0, (size)]
        int n =nums.size();
        int ans = n;
        for(int i=0;i<n;++i){
            ans += i-nums[i];
        }
        return ans;
    }
};