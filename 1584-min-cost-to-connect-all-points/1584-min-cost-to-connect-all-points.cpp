class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue< pair<int, pair<int, int> >, vector<pair<int, pair<int, int> >>, greater<pair<int, pair<int, int>> > > min_heap;
        unordered_set<int> uset; int totalPoints = points.size();
        
        int ansCost = 0;
        
        min_heap.push({0, {0, 0}});
        
        while(!min_heap.empty() and uset.size() != totalPoints){
            int curCost = min_heap.top().first; int curStart = min_heap.top().second.first, curEnd = min_heap.top().second.second;
            min_heap.pop();  
            
            if(uset.find(curEnd) != uset.end()) continue;
            
            // cout<<curCost<<" "<<curStart<<" "<<curEnd<<endl;
            ansCost += curCost; uset.insert(curEnd);
            
            for(int i=0; i<totalPoints; i++){
                if(uset.find(i) != uset.end()) continue;
                
                int curDist = dist(points[curEnd][0], points[curEnd][1], points[i][0], points[i][1]);
                min_heap.push({curDist, {curEnd, i}});
            }
            
        }
        return ansCost;
    }
    
    int dist(int x1, int y1, int x2, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }
};