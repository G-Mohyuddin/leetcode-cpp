class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> c(101); // we can also use a map but as constraints are small we are using an array of constant size
        int maxf = 0;
        int ans=0;
        for(int num : nums){
            c[num]++;
            int f = c[num];
            if(f>maxf){
                maxf=f;
                ans=maxf;
            }else if(f==maxf){
                ans+=maxf;
            }
        }
        return ans;
    }
};