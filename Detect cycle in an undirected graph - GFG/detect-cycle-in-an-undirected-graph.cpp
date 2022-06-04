// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int nVer = V;
        vector<int> vis(V, 0);
        
        for(int i=0; i<nVer; i++){
            if(!vis[i]){
                if(hasCycle(adj, nVer, vis, i)) return true;    
            }
        }
        
        return false;
    }
    
    bool hasCycle(vector<int> adj[], int nVer, vector<int> &vis, int node, int par=-1){
        vis[node] = 1;
        
        for(auto &adjNode: adj[node]){
            if(adjNode != par){
                if(vis[adjNode]) return true;
                
                if(hasCycle(adj, nVer, vis, adjNode, node)) return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends