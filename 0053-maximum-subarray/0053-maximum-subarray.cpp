class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int sz = arr.size();
	int localSum = arr[0];
	int globalSum = arr[0];

	for(int i=1; i<sz; i++){
		localSum = max(arr[i], arr[i] + localSum);

		globalSum = max(globalSum, localSum );
}

return globalSum;

    }
};