class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<  string, vector< pair<string, double>  >  > dirGraph;
        vector<double> output;
        
        for(int i=0; i<equations.size(); i++){
            dirGraph[equations[i][0]].push_back({equations[i][1], values[i]});
            dirGraph[equations[i][1]].push_back({equations[i][0], (double) ((double)1.0/values[i])});
        }
        
        for(auto pr: dirGraph){
            cout<<pr.first<<"-->";
            
            for(auto vecVal: pr.second){
                cout<<vecVal.first<<" "<<vecVal.second<<", ";
            }
            cout<<endl;
        }
        
        for(auto &curQ: queries){
            string num = curQ[0], den = curQ[1];
            if(dirGraph.find(num) == dirGraph.end() or dirGraph.find(den) == dirGraph.end()){
                output.push_back(-1.0); continue;
            }
            else if( num == den){
                output.push_back(1.0); continue;
            }
            
            map<string, int> vis; double ans = 1.0; int flag = 0;
            dfs(dirGraph, num, den, vis, ans, flag);
            
            if(flag == 0) {output.push_back(-1); continue;}
            output.push_back(ans);
        }
        
        return output;
    }
    
    
    void dfs(map<string, vector<pair<string, double>>> &dirGraph, string startNode, string endNode, map<string, int> &vis, double &ans,
             int  &flag, double curAns = 1.0 ){
        cout<<curAns<<" ";
        if(startNode == endNode){
            ans = curAns; flag = 1;
        }
        
        vis[startNode] = 1;
        
        for(auto &nodePair: dirGraph[startNode]){
            // curAns = 1.0;
            if(vis[nodePair.first]) continue;
            
            // curAns *= nodePair.second;
            
            dfs(dirGraph, nodePair.first, endNode, vis, ans, flag, curAns * nodePair.second);
        }
        
        // vis[startNode] = 0;
    }
};