class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int nEdges = connections.size();
        int extraEdges = nEdges - (n-1);
        
        if(extraEdges < 0) return -1;
        
        vector<int> adj[n];
        for(int i=0; i<nEdges; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int connComp = numConComp(adj, n);
        
        int reqEdges = connComp - 1;
        
//         if(reqEdges <= extraEdges){
//             return reqEdges;
//         }
        
        return reqEdges;
    }
    
    int numConComp(vector<int> adj[], int n){
        vector<int> vis(n, 0);
        int connComp = 0;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                connComp++;
            }
        }
        
        return connComp;
    }
    
    void dfs(vector<int> adj[], vector<int> &vis, int node){
        vis[node] = 1;
        
        for(auto &adjNode: adj[node]){
            if(!vis[adjNode]){
                dfs(adj, vis, adjNode);
            }
        }
    }
};