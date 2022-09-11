class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int size = nums.size(); 
        if(size ==1) return 0;
        int start = 0, end = size-1;
        int mid;
        
        while(start <= end){
            mid = start + (end - start)/2;
            
            if(mid-1 >=0 and mid +1 <= size-1){
                if(nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]) return mid;
                else{
                    if(nums[mid+1] > nums[mid]){
                        start = mid+1; 
                    }
                    else end = mid-1; 
                }
            }
            else{
                if(mid == 0 ){
                    if(nums[mid+1] > nums[mid]) return mid+1;
                    else return mid;
                }
                else{
                    if(nums[mid-1]> nums[mid]) return mid-1;
                    else return mid;
                }
            }
            
        }
        return mid;
        
    }
};