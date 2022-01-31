// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string> output;
        helper(n, dict, s, 0, "", output);
        return output;
    }
    
    void helper(int &n, vector<string>& dict, string &s, int curStrLoc, string curAns, vector<string> &output){
        // cout<<curStrLoc<<" ";
        if(curStrLoc == s.size()){output.push_back(curAns); return;}
        int dictSize = dict.size();
        for(int i=0; i<dictSize; i++){
            int curWrdSize = dict[i].size();
            if(curStrLoc+curWrdSize <= s.size() and  dict[i]  == s.substr(curStrLoc, curWrdSize)){
                string temp = curAns;
                if(!curAns.empty())curAns = curAns + " " + dict[i];
                else curAns += dict[i];
                helper(n, dict, s, curStrLoc+curWrdSize, curAns, output);
                curAns = temp;
            }
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends