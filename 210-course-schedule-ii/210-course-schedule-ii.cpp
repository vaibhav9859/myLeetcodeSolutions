class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int nVer = numCourses;
        vector<int> adj[nVer];
        vector<int> output;
        
        for(auto pr: prerequisites){
            adj[pr[1]].push_back(pr[0]);
        }
        
        vector<int> globCycleVis(nVer, 0);
        vector<int> cycleVis(nVer, 0);
        
        for(int i=0; i<nVer; i++){
            if(!cycleVis[i] and hasCycle(adj, cycleVis, globCycleVis, i)){
                return output;
            }
        }
        
        stack<int> st;
        vector<int> vis(nVer, 0);
        
        for(int i=0; i<nVer; i++){
            if(!vis[i]) {
                dfs(adj, i, st, vis);
                st.push(i);
            }
        }
        
    
        
        while(!st.empty()){
            output.push_back(st.top()); 
            st.pop();
        }
        
        return output;
    }
    
    bool hasCycle(vector<int> adj[], vector<int> &cycleVis, vector<int> &globCycleVis, int node){
        globCycleVis[node] = 1;
        cycleVis[node] = 1;

        for(auto adjNode: adj[node]){
            if(cycleVis[adjNode] == 1) return true;

            else if(!globCycleVis[adjNode] and hasCycle(adj, cycleVis, globCycleVis, adjNode)){
                return true;
            }
        } 
        
        cycleVis[node] = 0;
        return false;
    }    
    
    void dfs(vector<int> adj[], int node, stack<int> &st, vector<int> &vis){
        vis[node] = 1;
        
        for(auto &adjNode: adj[node]){
            if(!vis[adjNode]){
                dfs(adj, adjNode, st, vis);
                st.push(adjNode);
            }
        }
    }
};