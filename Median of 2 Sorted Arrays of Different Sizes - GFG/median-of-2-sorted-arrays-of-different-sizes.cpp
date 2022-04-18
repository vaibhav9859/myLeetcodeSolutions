// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {

        int sz1 = array1.size(), sz2 = array2.size();
        if(sz1 > sz2) return MedianOfArrays(array2, array1);
        
        int l = 0, h = sz1, cut1, cut2; 
        
        
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        
        while(l<=h){
            cut1 = (l+h)/2;
            cut2 = ((sz1 + sz2 +1)/2 )-cut1;
            
            // cout<<cut1<<" "<<cut2<<endl;
            
            l1 = INT_MIN;
            l2 = INT_MIN;
            r1 = INT_MAX;
            r2 = INT_MAX;
            
            if(cut1 > 0) l1 = array1[cut1-1]; 
            if(cut2 > 0) l2 = array2[cut2-1];
            
            if(cut1 < sz1 and cut1 >=0) r1 = array1[cut1];
            if(cut2 < sz2 and cut2 >=0) r2 = array2[cut2];
            
            // cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl<<endl;
            
            if(l1 <= r2 and l2 <= r1){
                if((sz1+sz2)%2) return max(l1, l2);
                else return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if(l1 > r2){
                h = cut1-1;
            }
            else l = cut1 + 1;
            
        }
        
        return 0.0;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends