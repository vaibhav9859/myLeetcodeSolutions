class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int sz = bombs.size();
        int maxCount = 1; 

        vector<int> adjList[sz];

        // creating adj list
        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
                long long x1 = bombs[i][0];
                long long y1 = bombs[i][1];
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long iRange = bombs[i][2];
                long long jRange = bombs[j][2];

                long long dist2 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

                if(iRange*iRange >= dist2){
                    adjList[i].push_back(j);
                }

                if(jRange*jRange >= dist2){
                    adjList[j].push_back(i);
                }
            }
        }

        

        // apply dfs at all points
        for(int i=0; i<sz; i++){
            unordered_set<int> visSet;
            visSet.insert(i);
            dfs(adjList, visSet, i);
            int sz = visSet.size();
            maxCount = max(maxCount, sz);
        }

        return maxCount;
    }

    void dfs(vector<int> adjList[], unordered_set<int> &visSet, int curNode){
        
        for(auto &adjNode: adjList[curNode]){
            if(visSet.find(adjNode) == visSet.end()){
                visSet.insert(adjNode);
                dfs(adjList, visSet, adjNode);
            }
        }
    }
};