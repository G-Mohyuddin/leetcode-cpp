class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> output;
        string result = "";
        int size=s.size();
        output.push(s[0]);
        for(int i=1;i<size;i++){
            if(!output.empty() && output.top()==s[i]){
                output.pop();
                continue;
            }
            output.push(s[i]);
        }
        while(!(output.empty())){
            result+=output.top();
            output.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};