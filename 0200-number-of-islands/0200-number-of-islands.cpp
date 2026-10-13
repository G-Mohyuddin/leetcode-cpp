class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> vis(rows,vector<int>(cols));
        int is=0;
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]=='1' && vis[i][j]!=1){
                    q.push({i,j});
                    vis[i][j]=1;
                    is+=1;
                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        for(int j=0;j<4;++j){
                            int nrow=r+dr[j];
                            int ncol=c+dc[j];
                            if(nrow>=0 && ncol>=0 && nrow<rows && ncol<cols && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0){
                                vis[nrow][ncol]=1;
                                q.push({nrow,ncol});
                            }
                        }
                    }
                }
            }
        }
        return is;
    }
};