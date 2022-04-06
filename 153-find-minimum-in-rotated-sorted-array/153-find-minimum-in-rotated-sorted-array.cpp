class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size()-1, mid;
        int sz = nums.size(); 
        
        cout<<l<<" "<<h<<endl;
        
        int ans = -1;
        
        while(l<=h){
            if(nums[l] <= nums[h]) return ans = nums[l];
            mid = (l+h)/2;
            
            if(nums[mid] <= nums[(mid+1)%sz] and nums[mid] <= nums[(mid-1+sz)%sz]){
                return ans = nums[mid];
            }
            else if(nums[mid] < nums[l]) h = mid-1;
            else l = mid+1;
        }
        
        return ans;
    }
};