class Solution {
public:
    vector<int> find_nse(vector<int>& arr){
        stack<int> s;
        int size=arr.size();
        vector<int> nse(size);
        for(int i=size-1;i>=0;--i){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            nse[i]=s.empty() ? size : s.top();
            s.push(i);
        }
        return nse;
    }
    vector<int> find_psse(vector<int>& arr){
        stack<int> s;
        int size=arr.size();
        vector<int> psse(size);
        for(int i=0;i<size;++i){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            psse[i]=s.empty() ? -1 : s.top();
            s.push(i);
        }
        return psse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = find_nse(arr);
        vector<int> psse = find_psse(arr);
        int size=arr.size();
        int ans=0;
        int mod=(int)(1e9+7);
        for(int i=0;i<size;++i){
            int left=i-psse[i];
            int right=nse[i]-i;
            ans=(ans+(right*left*(long long int)1*arr[i]))%mod;
        }
        return ans;
    }
};