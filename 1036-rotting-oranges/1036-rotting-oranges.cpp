class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[rows][cols];
        int max_fresh=0,cnt=0,mt=0;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    max_fresh++;
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            mt=max(mt,t);
            q.pop();
            for(int i=0;i<4;++i){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<rows && ncol<cols && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
        if(max_fresh!=cnt){
            return -1;
        }
        return mt;
    }
};