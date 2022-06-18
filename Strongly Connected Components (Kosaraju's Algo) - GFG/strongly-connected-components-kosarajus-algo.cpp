// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Three main things: Toposort, reverse graph, normal connected components finder
    int kosaraju(int V, vector<int> adj[])
    {
        int nVer = V;
        //Let's get the topoSort
        stack<int> st;
        topoSort(adj, nVer, st);
        
        //Let's transpose the graph
        vector<int> transAdj[nVer];
        transposeGraph(adj, nVer, transAdj);   
        
        //Let's find the number of connected compo
        //By doing dfs in topo sorted order
        return connComp(transAdj, nVer, st);
    }
    //Function 1 - Topo Sort
    void topoSort(vector<int> adj[], int nVer, stack<int> &st){
        vector<int> vis(nVer, 0);
        
        for(int i=0; i<nVer; i++){
            if(!vis[i]){
                topoDfs(adj, nVer, i, vis, st);
            }
        }
        
        return;
    }
    //Function 2 - Topo Sort Helper
    void topoDfs(vector<int> adj[], int nVer, int node, vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        
        for(auto &adjNode: adj[node]){
            if(!vis[adjNode]){
                topoDfs(adj, nVer, adjNode, vis, st);
            }
        }
        
        st.push(node);
    }
    //Function 3 - reverse graph
    void transposeGraph(vector<int> adj[], int nVer, vector<int> transAdj[]){
        for(int i=0; i<nVer; i++){
            for(auto &adjNode: adj[i]){
                transAdj[adjNode].push_back(i);
            }
        }
    }
    //Function 4 - No. of connected Compo in Transposed graph
    int connComp(vector<int> transAdj[], int nVer, stack<int> &st){
        int count = 0;
        vector<int> vis(nVer, 0);
        
        while(!st.empty()){
            int curNode = st.top();
            st.pop();
            if(!vis[curNode]){
                compDfs(transAdj, nVer, curNode, vis);
                count++;
            }
        }
        
        return count;
    }
    //Function 5 - DFS for connected Components
    void compDfs(vector<int> transAdj[], int nVer, int node, vector<int> &vis){
        vis[node] = 1;
        
        for(auto &adjNode: transAdj[node]){
            if(!vis[adjNode]){
                compDfs(transAdj, nVer, adjNode, vis);
            }
        }
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends