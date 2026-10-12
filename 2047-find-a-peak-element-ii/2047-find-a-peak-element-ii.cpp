class Solution {
public:
    int max_row(vector<vector<int>>& mat, int rows, int col){
    int max_val = -1;
    int max_index = -1;
    for(int i = 0; i < rows; ++i){
        if (mat[i][col] > max_val) {
            max_val = mat[i][col];
            max_index = i;
        }
    }
    return max_index;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> ans(2);
        int start = 0,end=cols-1;
        while(start<=end){
            int mid = start +((end-start)/2);
            int max_r = max_row(mat,rows,mid);
            int right = mid<cols-1? mat[max_r][mid+1] : -1;
            int left = mid>0? mat[max_r][mid-1] : -1;
            if(left>mat[max_r][mid]){
                end=mid-1;
            }else if(right>mat[max_r][mid]){
                start=mid+1;
            }else{
                ans[0]=max_r;
                ans[1]=mid;
                return ans;
            }
        }
        return ans;
    }
};