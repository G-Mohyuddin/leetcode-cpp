class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int size=heights.size();
        int max_height=0;
        for(int i=0;i<size;++i){
            while(!(s.empty())&&heights[s.top()]>heights[i]){
                int ind=s.top();
                s.pop();
                int nse=i;
                int pse=!s.empty() ? s.top() : -1;
                max_height=max(heights[ind]*(nse-pse-1),max_height);
            }
            s.push(i);
        }
        while(!s.empty()){
            int ind=s.top();
            s.pop();
            int nse=size;
            int pse=!s.empty() ? s.top() : -1;
            max_height=max(heights[ind]*(nse-pse-1),max_height);
        }
        return max_height;
    }
};