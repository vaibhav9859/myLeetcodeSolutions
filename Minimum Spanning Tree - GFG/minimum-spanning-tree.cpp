// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
   int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int> key(v,INT_MAX);
        vector<bool>mst(v,false);
        
        key[0]=0;
        
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
        
        pq.push({0,0});
        
        while (!pq.empty())
        {
            int u = pq.top().second;
            
            pq.pop();
            
            mst[u]=true;
            
            for (auto it:adj[u])
            {
                int x = it[0];
                int weight = it[1];
                
                if (mst[x]==false && weight<key[x])
                {
                    key[x] = weight;
                    pq.push({weight, x});
                }
            }
        }
        
        // for(auto &val: key){
        //     cout<<val<<" ";
        // }
        // cout<<endl;
        return accumulate(key.begin(), key.end(), 0);
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends