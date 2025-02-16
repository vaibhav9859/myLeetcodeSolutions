class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());

      int sz = nums.size();
      vector<vector<int>> output;

      for(int fIdx = 0; fIdx < sz; fIdx++){
        for(int sIdx = fIdx+1, tIdx = sz-1; sIdx < tIdx; ){
            int curSum = nums[fIdx] + nums[sIdx] + nums[tIdx];

            if(curSum == 0){
                output.push_back({nums[fIdx], nums[sIdx], nums[tIdx]});
                sIdx++;
                tIdx--;

                while(sIdx < sz and tIdx >= 0 and nums[sIdx-1] == nums[sIdx] and nums[tIdx+1] == nums[tIdx]){
                    sIdx++;
                    tIdx--;
                }
            }
            else if(curSum < 0){
                sIdx++;
            } 
            else {
                tIdx--;
            }
        }

        while(fIdx+1 < sz and nums[fIdx] == nums[fIdx+1]){
            fIdx++;
        }
      } 

      return output; 
    }
};