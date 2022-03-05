// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> output;
		    map<string, int> myMap;
		    helper(S, 0, myMap);
		    
		    for(auto it: myMap){
		        output.push_back(it.first);
		    }
		    
		    return output;
		}
		
		void helper(string S, int indexPos, map<string, int> &myMap){
		    int strSize = S.size();
		    if(indexPos == strSize-1){
		        myMap[S]++; return;
		    }
		    
		    for(int i = indexPos; i<strSize; i++){
		        string newStr = S;
		        swap(newStr[indexPos], newStr[i]);
		        helper(newStr, indexPos+1, myMap);
		    }
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends