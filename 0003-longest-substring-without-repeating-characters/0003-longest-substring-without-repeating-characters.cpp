class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size=s.length(),r=0,l=0;
        int ans=0,n=s.length();
        vector<int> hash(256,-1);
        while(r<n){
            if(hash[(int)s[r]]!=-1 && hash[(int)s[r]]>=l){
                l=hash[(int)s[r]]+1;
            }
            if(ans<r-l+1){
                ans=r-l+1;
            }
            hash[(int)s[r]]=r;
            r++;
        }
        return ans;
    }
};