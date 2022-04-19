class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair< float, pair<int, int>  >  >  maxHeap;
        vector<vector<int>> output;
        
        for(int i=0; i<points.size(); i++){
            double val = sqrt( points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            
            // cout<<val<<" "<<points[i][0]<<" "<<points[i][1]<<endl;
            
            if(maxHeap.size() < k) maxHeap.push( { val, {points[i][0], points[i][1]}  });
            else{
                if(maxHeap.top().first > val){
                    maxHeap.pop(); maxHeap.push( {val, {points[i][0], points[i][1]}  } );
                }
            }
        }
        
        while(!maxHeap.empty()){
            pair< float, pair<int, int>  > val = maxHeap.top(); maxHeap.pop();
            
            vector<int> temp;
            temp.push_back(val.second.first); temp.push_back(val.second.second);
            
            output.push_back(temp);
        }
        
        return output;
    }
};