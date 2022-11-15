class Solution {
public:
    
int firstOcc(vector<int>& arr, int x){
    int sz = arr.size();
    int l = 0, h = sz-1;
    int var = -1;

    while( l <= h){
        // Mid Point
        int midPoint = (l+h)/2;

        // Compare
        if(x == arr[midPoint]){
            var = midPoint;
            h = midPoint-1;
        }
        else if(x > arr[midPoint]) l = midPoint+1;
        else if(x < arr[midPoint]) h = midPoint-1;       
    }

    return var;
}
    
    
int lastOcc(vector<int>& arr, int x){
    int sz = arr.size();
    int l = 0, h = sz-1;
    int var = -1;

    while( l <= h){
        // Mid Point
        int midPoint = (l+h)/2;

        // Compare
        if(x == arr[midPoint]){
            var = midPoint;
            l = midPoint+1;
        }
        else if(x > arr[midPoint]) l = midPoint+1;
        else if(x < arr[midPoint]) h = midPoint-1;       
    }

    return var;
}
   
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        
        int firstIndex = firstOcc(nums, target);
        int lastIndex = lastOcc(nums, target);
        
        result.push_back(firstIndex);
        result.push_back(lastIndex);
        
        return result;
    }
};