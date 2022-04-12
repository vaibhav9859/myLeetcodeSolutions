// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    unordered_map<int, int> m;
    int val = 0;
    
    for(int i=0; i<size; i++){
         val = arr[i];
         m[val]++;
    }
    
    for(int i=0; i<size; i++){
        val = arr[i];
        if(val+n != val and m[val+n]) return true;
        else if(val+n == val and m[val+n] == 2) return true;
    }
    
    return false;
}