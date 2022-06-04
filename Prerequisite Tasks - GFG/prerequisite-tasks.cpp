// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prereq) {
	    // Code here 
	    int nVer = N;
	    vector<int> adj[nVer];
	    
	    for(auto pr: prereq){
	        adj[pr.second].push_back(pr.first);
	    }
	    
	    vector<int> vis(nVer, 0);
	    vector<int> curMovVis(nVer, 0);
	    
	    for(int i=0; i<nVer; i++){
	        if(!vis[i] and !hasCycle(adj, nVer, i, vis, curMovVis)){
	            return false;
	        }
	       // curMovVis.clear();
	    }
	    
	    return true;
	}
	
	bool hasCycle(vector<int> adj[], int nVer, int node, vector<int> &vis, vector<int> &curMovVis){
	    vis[node] = 1;
	    curMovVis[node] = 1;
	    
	    for(auto &adjNode: adj[node]){
	        if(curMovVis[adjNode]) return false;
	        
	        if(!vis[adjNode] and !hasCycle(adj, nVer, adjNode, vis, curMovVis)){
	            return false;
	        }
	 
	    }
	    
        curMovVis[node] = 0;
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends