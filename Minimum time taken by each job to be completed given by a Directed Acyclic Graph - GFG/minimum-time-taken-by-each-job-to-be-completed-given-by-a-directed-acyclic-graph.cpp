// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here  
            int nVer = n;
            int nEdg = m;
            
            vector<int> minTime(nVer, 0);
            vector<int> adj[nVer+1];
            vector<int> inDegree(nVer+1, 0);
            
            for(int i=0; i<nEdg; i++){
                adj[edges[i][0]].push_back(edges[i][1]);
                inDegree[edges[i][1]]++;
            }
            
            queue<int> q;
            for(int i=1; i<=nVer; i++){
                if(!inDegree[i]) q.push(i);
            }
            
            int curTime = 1;
            while(!q.empty()){
                int sz = q.size();
                
                for(int i=0; i<sz; i++){
                    int curNode = q.front();
                    q.pop();
                    minTime[curNode-1] = curTime;
                    
                    for(auto &adjNode: adj[curNode]){
                        if(inDegree[adjNode] > 0){
                            inDegree[adjNode]--;
                            
                            if(!inDegree[adjNode]){
                                q.push(adjNode);
                            }
                        }
                    }
                }
                
                curTime++;
            }
            
         return minTime;   
        }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends