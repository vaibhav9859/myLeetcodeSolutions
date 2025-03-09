class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
        if(v1[1] < v2[1]) return true;
        if(v1[1] < v2[1] and v1[0] < v2[0]) return true;
        return false;
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int count = 1;
        int endTime = points[0][1];
        int sz= points.size();

        for(int i=0; i<sz; i++){
            if(endTime >= points[i][0]){
                continue;
            }    
            else{
                count++;
                endTime = points[i][1];
            }
        }

        return count;
    }
};