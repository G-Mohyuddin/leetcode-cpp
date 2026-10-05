class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int size=asteroids.size();
        for(int i=0;i<size;++i){
            while(!ans.empty() && ans.back()>0 && asteroids[i]<0){
                if(abs(ans.back())<abs(asteroids[i])){
                    ans.pop_back();
                }else if(abs(ans.back())==abs(asteroids[i])){
                    ans.pop_back();
                    asteroids[i]=0;
                }else{
                    asteroids[i]=0;
                }
            }
            if(asteroids[i]!=0){
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};