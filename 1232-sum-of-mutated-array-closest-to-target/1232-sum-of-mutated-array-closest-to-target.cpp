class Solution {
public:
long long findSum(vector<int>& arr, int value){
	long long sum = 0;
    for(auto &val: arr){
        if(val > value) sum += value;
        else sum += val;
    }

    return sum;
}

int findBestValue(vector<int>& arr, int target) {
	
	int ans = -1;
	
	sort(arr.begin(), arr.end());
    int start = 0, end = arr.back();
    long long minDiff = LLONG_MAX;
	while(start <= end){
		int mid = (start+end)/2;

		long long curSum = findSum(arr, mid);
        long long diff = abs(curSum - target);
        if(minDiff > diff or (minDiff == diff and mid < ans)){
            minDiff = diff;
            ans = mid;
        }

		
        else if (curSum > target){
            // ans = mid;
            end = mid-1;
        }
        else{
            // ans = mid;
            start = mid+1;
        }
    }
                
    return ans;
}

};