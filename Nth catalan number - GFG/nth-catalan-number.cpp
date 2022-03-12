// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        //code here
        cpp_int nume = 1;
        cpp_int deno = 1;
        
        cpp_int tn = 2*n;
        cpp_int nn = n;
        
        for(int i=0; i<n; i++){
            nume *= tn; tn -= 1;
            deno *= nn; nn -= 1;
        }
        
        cpp_int ans = nume/deno;
        ans /= n+1;
        
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends