// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int ans = 1;
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({end[i], start[i]});
        }
        
        sort(v.begin(), v.end());
        
        // for(int i=0; i<n; i++){
        //       cout<<v[i].second<<" "<<v[i].first<<endl;
        // }
        // cout<<endl;
        int prevIndex = 0;
        for(int i=1; i<n;){
            if(v[i].second > v[prevIndex].first){
                prevIndex = i;
                ans++; i++;
                
            }
            else i++;
            
            // cout<<ans<<" "<<v[i].second<<" "<<v[i].first<<endl;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends