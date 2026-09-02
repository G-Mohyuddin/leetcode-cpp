class Solution {
public:
    int firstUniqChar(string s) {
        queue<char> q;
        map<char,int> hashmap;
        int size=s.length();
        for(int i=0;i<size;++i){
            q.push(s[i]);
            hashmap[s[i]]+=1;
        }
        for(int i=0;i<size;++i){
            char temp=q.front();
            q.pop();
            if(hashmap[temp]==1){
                return i;
            }
        }
        return -1;
    }
};