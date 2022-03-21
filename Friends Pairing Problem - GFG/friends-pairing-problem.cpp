// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:


    int countFriendsPairings(int n) 
    { 
        // code here
        if(n==1 or n==2) return n;
        // return countFriendsPairings(n-1) + (n-1)*countFriendsPairings(n-2);
        int MOD = 1000000007;
        
        long long int n1 = 1, n2 = 2;
        
        for(int i=3; i<=n; i++){
            int temp = n2;
            n2 = (n2%MOD + ((i-1)%MOD * n1%MOD)%MOD)%MOD;
            n1 = temp;
        }
        
        return n2%MOD;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends