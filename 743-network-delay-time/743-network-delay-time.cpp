class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        int ans = INT_MIN;

        int nEdg = times.size();
        int nVer = n;
        
        for(int i=0; i<nEdg; i++){
            adj[times[i][0]].push_back({times[i][2], times[i][1]});
        }
        
        vector<int> time_output(n+1, INT_MAX);
        time_output[k] = 0;
        
        dikstra(adj, time_output, k);
        
        
        for(int i=1; i<=n; i++){
            // cout<<time_output[i]<<" ";
            ans = max(ans, time_output[i]);
        }
        
        if(ans != INT_MAX) return ans;
        
        return -1;
    }
    
    void dikstra(vector<pair<int, int>> adj[], vector<int> &time_output, int k){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        min_heap.push({0, k});
        
        while(!min_heap.empty()){
            int curDist = min_heap.top().first;
            int curVer = min_heap.top().second;
            min_heap.pop();
            
            for(auto &adjNode: adj[curVer]){
                int newDist = curDist + adjNode.first;
                int vertex = adjNode.second;
                if(newDist < time_output[vertex]){
                    time_output[vertex] = newDist;
                    min_heap.push({newDist, vertex});
                }
            }
        }
    }
};