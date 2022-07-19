class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int localSum = arr[0], globalSum = arr[0];
        int sz = arr.size();
        
        for(int i=1; i<sz; i++){
            if(localSum + arr[i] > arr[i]){
                localSum += arr[i];
            }
            else localSum = arr[i];
            
            
            globalSum = max(localSum, globalSum);
        }
        
        return globalSum;
    }
};