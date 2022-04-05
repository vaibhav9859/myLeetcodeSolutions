class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1, mid;
        
        while(low <= high){
            cout<<low<<" "<<high<<endl;
            mid = (low + high)/2;
            
            if(target == arr[mid]) return mid;
            else if(arr[low] <= arr[mid]){
                if(target>=arr[low] and target<=arr[mid]) high = mid-1;
                else low = mid+1;
            }
            else {
                if(target >= arr[mid] and target <= arr[high]) low = mid+1;
                else high = mid - 1;                
            }
        }
        
        return -1;
    }
};