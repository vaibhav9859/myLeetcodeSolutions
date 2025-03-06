class Solution {
public:
    bool checkPossibility(vector<int>& arr) {
        int count = 0;
        int sz = arr.size();

        for(int i=1; i<sz; i++){
            if(arr[i-1] > arr[i]){
                if(i-2 < 0 or arr[i-2] < arr[i]){
                    arr[i-1] = arr[i];
                }
                else {
                    if(arr[i-2] > arr[i]){
                        arr[i] = arr[i-1];
                    }
                }

                count++;
                if(count > 1) return false;
            }
        }

        return true;
    }
};