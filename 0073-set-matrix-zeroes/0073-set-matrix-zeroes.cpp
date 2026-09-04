class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row=false;
        int rows = matrix.size();
        int columns = matrix[0].size();
        for(int i=0;i<rows;++i){
            for(int j=0;j<columns;++j){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    if(i>0){
                        matrix[i][0]=0;
                    }else{
                        first_row=true;
                    }

                }
            }
        }
        for(int i=1;i<rows;++i){
            for(int j=1;j<columns;++j){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=0;i<rows;++i){
                matrix[i][0]=0;
            }
        }
        if(first_row){
            for(int i=0;i<columns;++i){
                matrix[0][i]=0;
            }
        }
    }
};