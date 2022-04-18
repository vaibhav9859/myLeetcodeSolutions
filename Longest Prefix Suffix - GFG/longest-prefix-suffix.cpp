// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    
	    vector<int> preArr(s.size(), 0);
	    
	    int front = 1, back = 0;
	    for(int i=1; i<s.size(); i++){
	        
	        if(s[front] == s[back]){
	            preArr[i] = back+1; front++; back++;
	        }
	        else{
	            back = back-1; back = preArr[back];
	            while(back != 0 and s[back] != s[front]){
	                back = preArr[back-1];
	            }
	            
    	        if(s[front] == s[back]){
    	            preArr[i] = back+1; front++; back++; 
    	        }
    	        else{
    	            preArr[i] = 0; front++;  
    	        }
	        }
	    }
	    
	    return preArr[s.size()-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends