class Solution {
public:
    void nextPermutation(vector<int>& arr) {
                   int N = arr.size();
        int pos = -1;
        
        for(int i=N-2; i>=0; i--){
            if(arr[i] < arr[i+1]){
                pos = i; 
                break;
            }
        }
        
        if(pos == -1) {
            reverse(arr.begin(), arr.end());
            return;
        }
        
        int justGrtIn = -1;
        int curMax = INT_MAX;
        for(int i=pos+1; i<N; i++){
            if(arr[i] <= curMax and arr[i] > arr[pos]){
                curMax = arr[i];
                justGrtIn = i;
            }
        }
        
        
        swap(arr[pos], arr[justGrtIn]);
        
        reverse(arr.begin()+pos+1, arr.end());
        return;
    }
    
    
};