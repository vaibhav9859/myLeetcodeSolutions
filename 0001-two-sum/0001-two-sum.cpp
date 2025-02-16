class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valToIdx;
        int sz = nums.size();

        for(int i=0; i<sz; i++){
            valToIdx[nums[i]] = i;
        }

        vector<int> output;

        for(int i=0; i<sz; i++){
            int otherVal = target - nums[i];
            if(valToIdx.find(otherVal) != valToIdx.end() and valToIdx[otherVal] != i){
                output.push_back(i);
                output.push_back(valToIdx[otherVal]);
                return output;
            }
        }

        return output;
    }
};