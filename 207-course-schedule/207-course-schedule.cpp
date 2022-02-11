class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses, 0);
        vector<int> curVis(numCourses, 0);
        
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                
                if(hasCycle(i, adj, numCourses, visited, curVis)) return false;
            }
        }
        return true;
    }
    
    bool hasCycle(int curNode, vector<int> adj[], int &v, vector<int> &visited, vector<int> &curVis){
        
        visited[curNode] = 1;   
        curVis[curNode] = 1;
        for(auto node: adj[curNode]){
            if(!visited[node]){
                if(hasCycle(node, adj, v, visited, curVis)) return true;
            }    
            else if(curVis[node]) return true;
        }
        curVis[curNode] = 0;
        
        return false;
    }
};