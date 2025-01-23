class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> adjList[n+1];
        unordered_map<int, int> inDeg;

        for(auto &edgeNodes: relations){
            adjList[edgeNodes[0]].push_back(edgeNodes[1]);
            inDeg[edgeNodes[1]]++;
        }

        queue<int> bfsQueue;
        int semsReq = 0;
        int visCount = 0;

        for(int i=1; i<=n; i++){
            if(inDeg.find(i) == inDeg.end()){
                bfsQueue.push(i);
            }
        }
 
        while(!bfsQueue.empty()){
            int sz = bfsQueue.size();
            semsReq++;

            while(sz--){
                int curCourse = bfsQueue.front();
                bfsQueue.pop();
                visCount++;

                for(auto &newCourse: adjList[curCourse]){

                    if(--inDeg[newCourse] == 0){
                        bfsQueue.push(newCourse);
                    } 

                    // if(inDeg[newCourse] < 0) return -1;
                }
            }
        }

        int ans = visCount == n ? semsReq : -1; 


        return ans;
        // return semsReq;
    }
};