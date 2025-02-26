class Solution {
public:
    void upper(vector<int> &lonSubSeq, int val){
        int start = 0, end = lonSubSeq.size()-1;
        int loc;

        while(start <= end){
            int mid = (start+end)/2;

            if(val == lonSubSeq[mid]){
                return;
            }
            else if(val < lonSubSeq[mid]){
                loc = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        lonSubSeq[loc] = val;
        return;
    }

    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<int> lonSubSeq;

        for(int i=0; i<sz; i++){
            if(lonSubSeq.empty()){
                lonSubSeq.push_back(nums[i]);
            }    
            else if(lonSubSeq.back() < nums[i]) {
                lonSubSeq.push_back(nums[i]);
            }
            else{
                // upper(lonSubSeq, nums[i]);
                int loc = lower_bound(lonSubSeq.begin(), lonSubSeq.end(), nums[i]) - lonSubSeq.begin();
                lonSubSeq[loc] = nums[i];
            }
        }

        return lonSubSeq.size();
    }
};