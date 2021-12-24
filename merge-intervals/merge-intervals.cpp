class Solution {
public:
    // static bool compare(vector<int> x, vector<int> y){
    //     return x[0] <= y[0];
    // }
    static bool compare (vector<int> p1, vector<int> p2) {
    return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
}
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        sort(intervals.begin(), intervals.end(), compare);
        
        int f, s; f=intervals[0][0], s = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            
            if(s >= intervals[i][0]){
                
                if(s <= intervals[i][1]){
                    s =intervals[i][1];
                    
                }
               
            }
            else{
                output.push_back({f, s});
                f=intervals[i][0], s = intervals[i][1];
               
                
            }
        }
        output.push_back({f, s});
        
        return output;
    }
};