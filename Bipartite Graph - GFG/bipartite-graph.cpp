// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){

	    vector<int> color(V, -1);
	    int nVer = V;
	    
	    for(int i=0; i<nVer; i++){
	        if(color[i] == -1 and !bfs(adj, i, color)){
	            return false;   
	        }
	    }
	    
	    return true;
	}
	
	bool bfs(vector<int>adj[], int node, vector<int> &color){
	
	    queue<int> q;
	    q.push(node);
	    int col = 0;
	    
        while(!q.empty()){
    	    int sz = q.size();
    	    for(int i=0; i<sz; i++){
    	        
    	        int curNode = q.front(); q.pop();
    	        
    	        if(color[curNode] == 1-col) return false;
    	        color[curNode] = col;
    	        
    	        for(auto adjNode: adj[curNode]){
    	            if(color[adjNode] == -1){
    	                q.push(adjNode);
    	            }
    	            else{
    	                if(color[adjNode] != 1-col) return false; 
    	            }
    	        }
    	    }
    	    
    	    col = 1-col;
        }
        
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends