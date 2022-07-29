class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        
        if(sz2 < sz1) return findMedianSortedArrays(nums2, nums1);
        
        int l = 0, h = sz1;
        
        while(l <= h){
            int cut1 = (l+h)/2;
            int cut2 = (sz1 + sz2 + 1)/2 - cut1;
            
            int left1 = INT_MIN;
            int left2 = INT_MIN;
            int right1 = INT_MAX;
            int right2 = INT_MAX;
            
            if(cut1-1 >= 0) left1 = nums1[cut1-1];
            if(cut2-1 >= 0) left2 = nums2[cut2-1];
            if(cut1 < sz1) right1 = nums1[cut1];
            if(cut2 < sz2) right2 = nums2[cut2];
            
            
            if(left1 <= right2 and left2 <= right1){
                if((sz1 + sz2)%2){
                    return max(left1, left2);
                }
                else{
                    return (max(left1, left2) + min(right1, right2))/2.0;
                }
            }
            else if(left1 > right2){
                h = cut1-1;
            }
            else if(left2 > right1){
                l = cut1+1;
            }
        }
        
        return 0.0;
    }
};