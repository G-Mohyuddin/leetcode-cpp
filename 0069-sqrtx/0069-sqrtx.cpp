class Solution {
public:
    int mySqrt(int x) {
        if(x==1){return 1;}
        int start = 1;
        int end = x/2;
        while(start<=end){
            int mid=start+((end-start)/2);
            if((long long int)mid*mid>x){
                end=mid-1;
            }else if((long long int)mid*mid<x){
                start=mid+1;
            }else{
                return mid;
            }
        }
        return end;
    }
};