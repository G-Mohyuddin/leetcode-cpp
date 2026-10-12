class Solution {
public:
    bool is_possible(vector<int>& days,int day,int m,int k){
        int size=days.size();
        int c=0,b=0;
        for(int i=0;i<size;++i){
            if(day>=days[i]){
                c++;
                if(c==k){
                    b++;
                    c=0;
                }
            }else{
                c=0;
            }
            if(c==k){
                b++;
                c=0;
            }
            if(b>=m){
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int size=bloomDay.size();
        if(size/k<m){
            return -1;
        }
        auto temp= minmax_element(bloomDay.begin(),bloomDay.end());
        int start = *temp.first;
        int end = *temp.second;
        while(start<=end){
            int mid = start + ((end-start)/2);
            if(is_possible(bloomDay,mid,m,k)){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return start;
    }
};