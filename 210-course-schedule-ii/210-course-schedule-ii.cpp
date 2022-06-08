class Solution {
public:
    //Function 1
    //Here we are first finding if there is a cycle in directed graph
    //Then we are finding the topological sorting
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int nVer = numCourses;
        vector<int> adj[nVer];
        vector<int> output;
        
        for(auto pr: prerequisites){
            adj[pr[1]].push_back(pr[0]);
        }
        
        //Below part is checking for cycle
        vector<int> globCycleVis(nVer, 0);
        vector<int> cycleVis(nVer, 0);
        
        for(int i=0; i<nVer; i++){
            if(!cycleVis[i] and hasCycle(adj, cycleVis, globCycleVis, i)){
                return output;
            }
        }
        
        //Below code for Topological sorting
        stack<int> st;
        vector<int> vis(nVer, 0);
        
        for(int i=0; i<nVer; i++){
            if(!vis[i]) {
                dfs(adj, i, st, vis);
            }
        }
        
    
        //puting the topo sorted data in output vector
        while(!st.empty()){
            output.push_back(st.top()); 
            st.pop();
        }
        
        return output;
    }
    
    //Function 2
    //Detecting Cycle in a directed graph
    bool hasCycle(vector<int> adj[], vector<int> &cycleVis, vector<int> &globCycleVis, int node){
        globCycleVis[node] = 1;
        cycleVis[node] = 1;

        for(auto adjNode: adj[node]){
            if(cycleVis[adjNode] == 1) return true;

            else if(!globCycleVis[adjNode] and hasCycle(adj, cycleVis, globCycleVis, adjNode)){
                return true;
            }
        } 
        
        //Very IMP line, when moving back
        //Unvisiting that node in local visited array
        cycleVis[node] = 0;
        return false;
    }    
    
    //Function 3
    //Putting topo sort in the stack
    //Basic idea is apply dfs
    //In DFS, when leaving the node simply put it in stack
    
    void dfs(vector<int> adj[], int node, stack<int> &st, vector<int> &vis){
        vis[node] = 1;
        
        for(auto &adjNode: adj[node]){
            if(!vis[adjNode]){
                dfs(adj, adjNode, st, vis);
            }
        }
        st.push(node);
    }
};