class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size(),cols = grid[0].size();
        int row = rows-1,col = 0;
        int ans=0;
        while(col<cols && row>=0){
            if(grid[row][col]>=0){
                col++;
            }else{
                ans+=cols-col;
                row--;
            }
        }
        return ans;
    }
};