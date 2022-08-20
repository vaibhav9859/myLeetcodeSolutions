class Solution {
public:
//     int search(vector<int>& nums, int target) {
        
//     }
    
    int search(vector<int> arr, int tar){

        int low = 0, high = arr.size()-1;


        while(low <= high){
                int mid = (low + high)/2;

                if(arr[mid] == tar) return mid;
                else{
                    if(mid-1 >= low and arr[low] <= arr[mid-1]){
                        if(tar >= arr[low] and tar <= arr[mid-1]) high = mid-1;
                        else low = mid+1;
                    }
                    else{
                        if(mid+1 <= high and tar >= arr[mid+1] and tar <= arr[high]) low = mid+1;
                        else high = mid-1;
                    }
                }
        }

        return -1;
    }
};