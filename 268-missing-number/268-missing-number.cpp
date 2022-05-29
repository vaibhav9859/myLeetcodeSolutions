class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i, missNo=nums[0], j=0;
        for(i=1;i<nums.size();i++){
            missNo^=nums[i];
            j^=i;
        }
        j^=nums.size();
        missNo=missNo^j;
        
        return missNo;
    }
};