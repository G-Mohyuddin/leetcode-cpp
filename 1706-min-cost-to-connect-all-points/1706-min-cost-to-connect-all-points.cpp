class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        //adjacency matrix which connects indices (nodes) to pairs <cost,neighbours>
        vector<vector<pair<int,int>>> adj(size);
        for(int i=0;i<size;++i){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<size;++j){
                int x2=points[j][0];
                int y2=points[j][1];
                int d = abs(x1-x2) + abs(y1-y2);
                adj[i].push_back({d,j});
                adj[j].push_back({d,i});
            }
        }
        //prim's algo implimentation of min spanning tree
        //pick any point and apply greedy algo

        int ans = 0;
        set<int> vis;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        min_heap.push({0,0});
        while(vis.size()<size){
            pair<int,int> cur = min_heap.top();
            min_heap.pop();
            if(vis.find(cur.second) != vis.end()){
                continue;
            }
            int cost = cur.first;
            int i = cur.second;
            ans+=cost;
            vis.insert(i);
            for (pair<int,int> neighbour : adj[i]){
                if(vis.find(neighbour.second) == vis.end()){
                    min_heap.push({neighbour.first,neighbour.second});
                }
            }
        }
        return ans;
    }
};