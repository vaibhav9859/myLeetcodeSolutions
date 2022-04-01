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
         
         int fv = intervals[0][0], sv = intervals[0][1];
         
         for(int i=1; i<rowsz; i++){
             if(sv >= intervals[i][0]){
                 sv = max(sv, intervals[i][1]);
             }
             else{
                 vector<int> temp; temp.push_back(fv); temp.push_back(sv);
                 output.push_back(temp);
                 fv = intervals[i][0]; sv = intervals[i][1];
             }
         }
         
        vector<int> temp; temp.push_back(fv); temp.push_back(sv);
        output.push_back(temp);        
        //  for(int i=0; i<rowsz; i++){
        //      for(int j=0; j<colsz; j++){
        //          cout<<intervals[i][j]<<" ";
        //      }
        //      cout<<endl;
        //  }
         
         
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