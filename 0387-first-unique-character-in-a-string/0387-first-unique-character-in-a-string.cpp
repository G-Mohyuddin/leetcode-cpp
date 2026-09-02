class Solution {
public:
    int firstUniqChar(string s) {
        queue<char> q;
        int freq[26] = {0};
        int size=s.length();
        for(int i=0;i<size;++i){
            q.push(s[i]);
            freq[s[i]-'a']+=1;
        }
        for(int i=0;i<size;++i){
            char temp=q.front();
            q.pop();
            if(freq[temp-'a']==1){
                return i;
            }
        }
        return -1;
    }
};