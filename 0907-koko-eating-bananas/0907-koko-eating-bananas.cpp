class Solution {
public:
    int find_max(vector<int>& a){
        int maxa=a[0];
        int n=a.size();
        for(int i=0;i<n;++i){
            maxa=max(maxa,a[i]);
        }
        return maxa;
    }
    long long int find_total_hour(vector<int>& a,int hourly){
        int size=a.size();
        long long int total = 0;
        for(int i=0;i<size;++i){
            total+=ceil(a[i]/(double)hourly);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end=find_max(piles);
        while(start<=end){
            int mid = start +((end-start)/2);
            long long int total_h = find_total_hour(piles,mid);
            if(total_h<=h){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return start;
    }
};