class Solution {
public:
    bool checkCollinear(int &x1, int &y1, int &x2, int &y2){
        return (x1 == x2 or y1 == y2) ? true : false;
    }

    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int, int>> uniquePts;
        int sz = points.size();
        int minArea = INT_MAX;

        for(auto &point: points){
            uniquePts.insert({point[0], point[1]});
        }

        for(int i=0; i<sz; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1; j<sz; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(!checkCollinear(x1, y1, x2, y2)){
                    if(uniquePts.find({x1,y2}) != uniquePts.end() and uniquePts.find({x2,y1}) != uniquePts.end()){
                        minArea = min(minArea, (abs(x1-x2) * abs(y1-y2)));
                    }
                }
            }
        }

        
        return minArea == INT_MAX ? 0 : minArea;
    }
};