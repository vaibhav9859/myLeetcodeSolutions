// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V, 0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(helper(adj, i, visited)) return true;
            }
        }
        return false;
    }
    
    bool helper(vector<int> adj[], int curNode, vector<int> &visited){
        queue<pair<int, int>> q;
        q.push({curNode, -1}); visited[curNode] = 1;
        
        while(!q.empty()){
            pair<int, int> pNode = q.front();
            for(auto a: adj[pNode.first]){
                
                if(visited[a] and a!=pNode.second) return true;
                if(a==pNode.second) continue;
                visited[a] = 1; q.push({a, pNode.first});
                
                
            }
            q.pop();
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