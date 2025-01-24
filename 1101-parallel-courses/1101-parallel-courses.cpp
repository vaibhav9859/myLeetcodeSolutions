class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        
        // adjList
        vector<int> graph[n+1];

        // inDeg Cal
        unordered_map<int, int> courseInDeg;

        for(auto &relation: relations){
            graph[relation[0]].push_back(relation[1]);
            courseInDeg[relation[1]]++;
        }

        int semsReq = 0;
        int studied = 0;

        queue<int> bfsQ;

        for(int i=1; i<=n; i++){
            if(courseInDeg.find(i) == courseInDeg.end()){
                bfsQ.push(i);
            }
        }

        while(!bfsQ.empty()){
            int sz = bfsQ.size();
            semsReq++;
            
            while(sz--){
                int curCourse = bfsQ.front();
                bfsQ.pop();

                studied++;

                for(auto &adjCourse: graph[curCourse]){
                    if(--courseInDeg[adjCourse] == 0){
                        bfsQ.push(adjCourse);
                    } 
                }
            }
        }
       
        return studied == n ? semsReq : -1;
    }
};  