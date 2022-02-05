class Solution {
public:
    
    static bool compare(pair<int, int> p1, pair<int, int> p2){
        if(p1.first < p2.first) return true;
        if(p1.first == p2.first and p1.second < p2.second) return true;
        return false;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v; 
        vector<int> output;
        for(int i=0; i<nums.size(); i++){
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end(), compare);
        
        for(int i=0, j=v.size()-1; i<j ; ){
            if(v[i].first + v[j].first == target){output.push_back(v[i].second); output.push_back(v[j].second); return output;}
            else if(v[i].first + v[j].first < target) i++;
            else j--;
        }
        
        return output;
    }
};