class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> prefix_sum(rows,vector<int>(cols));
        int max_area=0;
        for(int j=0;j<cols;++j){
            int sum=0;
            for(int i=0;i<rows;++i){
                sum++;
                if(matrix[i][j]=='0'){
                    sum=0;
                }
                prefix_sum[i][j]=sum;
            }
        }
        for(int i=0;i<rows;++i){
            max_area=max(max_area,lra(prefix_sum[i]));
        }
        return max_area;
    }
    int lra(vector<int> h){
        int size=h.size();
        stack<int> s;
        int max_area=0;
        for(int i=0;i<size;++i){
            while(!s.empty() && h[i]<h[s.top()]){
                int ind=s.top();
                s.pop();
                max_area=max(max_area,h[ind]*((i)-(!s.empty() ? s.top() : -1)-1));
            }
            s.push(i);
        }
        while(!s.empty()){
            int ind=s.top();
            s.pop();
            max_area=max(max_area,h[ind]*((size)-(!s.empty() ? s.top() : -1)-1));
        }
        return max_area;
    }
};