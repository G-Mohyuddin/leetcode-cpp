class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        int start = 0;
        int end = (rows*cols)-1;
        while(start<=end){
            int mid = start + ((end-start)/2);
            //formula to convert 1d number to 2d coordinates
            int r = mid/cols;
            int c = mid%cols;
            if(target>matrix[r][c]){
                start=mid+1;
            }else if(target<matrix[r][c]){
                end=mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};