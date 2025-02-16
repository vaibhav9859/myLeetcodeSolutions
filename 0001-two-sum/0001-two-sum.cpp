class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> valIdx;
        int sz = nums.size();

        for(int i=0; i<sz; i++){
            valIdx.push_back({nums[i], i});
        }

        sort(valIdx.begin(), valIdx.end());
        
        vector<int> output;

        for(int start=0, end=sz-1; start<end; ){

            int curSum = valIdx[start].first + valIdx[end].first;

            if(curSum == target){
                output.push_back(valIdx[start].second);
                output.push_back(valIdx[end].second);
                return output;
            }
            else if(target < curSum) end--;
            else start++;
        }

        return output;
    }
};