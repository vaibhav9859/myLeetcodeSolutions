// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int ans = 0;
	    
	    int patLen = pat.size(), txtLen = txt.size();
	    unordered_map<char, int> mPat, mTxt;
	    
	    for(int i=0; i<patLen; i++){
	        mPat[pat[i]]++; mTxt[txt[i]]++;
	    }
	    
	    for(int start=0, end=patLen-1; end<txtLen; ){
	        if(mPat == mTxt) ans++;
	        
	        mTxt[txt[start]]--; 
	        
	        if(!mTxt[txt[start]]) mTxt.erase(txt[start]);
	        
	        
	        
	        start++; end++;
	        
	        if(end < txtLen) mTxt[txt[end]]++;
	    }
	    
	    
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends