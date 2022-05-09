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
        //What matters here is end time, When did the prev meeting ended
        //So first task should be to sort these meeting with respect to end times
        
        vector<pair<int, int>> meets;
        
        for(int i=0; i<n; i++){
            meets.push_back({end[i], start[i]});
        }
        
        //Now sorting with respect to end timings
        sort(meets.begin(), meets.end());
        
        //Now simple traverse and check what meeting can be accomodated
        //By checking end time of previous meeting with start time of next one
        
        
        //We need a variable prev to know what is the last meeting we considered
        int result = 0;
        int prevMeetingEndTime = -1;
        
        for(auto &prValues: meets){
            if(prevMeetingEndTime == -1){
                 result++; 
                 prevMeetingEndTime = prValues.first; 
            }
            else{
                if(prValues.second > prevMeetingEndTime){
                    result++; 
                    prevMeetingEndTime = prValues.first;
                }
            }
        }
        
        return result;
        
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