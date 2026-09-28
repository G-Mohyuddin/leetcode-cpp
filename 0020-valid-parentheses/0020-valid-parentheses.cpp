class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int size=s.length();
        if (size==0){return true;}
        for(int i=0;i<size;++i){
            if(s[i]==')'){
                if(!(st.empty()) && st.top()=='('){
                    st.pop();
                }else{
                    return false;
                }
            }else if(s[i]==']'){
                if(!(st.empty()) && st.top()=='['){
                    st.pop();
                }else{
                    return false;
                }
            }else if(s[i]=='}'){
                if(!(st.empty()) && st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                st.push(s[i]);
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};