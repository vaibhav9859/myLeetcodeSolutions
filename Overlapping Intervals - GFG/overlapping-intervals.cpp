// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         vector<vector<int>> output;
         int rowsz = intervals.size(), colsz = intervals[0].size();
         
         sort(intervals.begin(), intervals.end());
         
         output.push_back(intervals[0]);
         
         for(int i=1; i<rowsz; i++){
             int sz = output.size() - 1;
             if(output[sz][1] >= intervals[i][0]){
                 output[sz][1] = max(output[sz][1], intervals[i][1]);
             }
             else{
                 output.push_back(intervals[i]);
             }
         }
         
        return output;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends