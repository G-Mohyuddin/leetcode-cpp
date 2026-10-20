class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int size = graph.size();
        if(size==0 || size==1){
            return 0;
        }
        // storing nodes in queue as {node,bit mask}
        set<pair<int,int>> vis;
        queue<pair<int,int>> q;
        for(int i=0;i<size;++i){
            q.push({i,1<<i});
            vis.insert({i,1<<i});
        }
        int the_end_state = (1 << size) -1; //same as pow(2,size)-1
        int path =0;
        while(!q.empty()){
            int s = q.size();
            path++;
            while(s--){
                pair<int,int> cur = q.front();
                q.pop();
                int cur_mask = cur.second;
                int cur_node = cur.first;
                for(int neighbour : graph[cur_node]){
                    int next_mask = cur_mask | (1<<neighbour);
                    if(next_mask == the_end_state){
                        return path;
                    }
                    if(vis.find({neighbour,next_mask})==vis.end()){
                        vis.insert({neighbour,next_mask});
                        q.push({neighbour,next_mask});
                    }
                    
                }
            }
        }
        return -1;
    }
};