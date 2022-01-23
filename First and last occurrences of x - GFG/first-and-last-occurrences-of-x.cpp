// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


int fo(int *arr, int n, int x){
    int ans = -1; int mid = 0, l = 0, h = n-1;
    while(l <= h){
        mid = (l+h)/2;
        if(arr[mid] == x){
            ans = mid; h = mid-1;
        }
        else if(x<arr[mid]){
            h = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}

int lo(int *arr, int n, int x){
    int ans = -1; int mid = 0, l = 0, h = n-1;
    while(l <= h){
        mid = (l+h)/2;
        if(arr[mid] == x){
            ans = mid; l = mid+1;
        }
        else if(x<arr[mid]){
            h = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}


vector<int> find(int arr[], int n , int x )
{
    vector<int> output;
    output.push_back(fo(arr, n, x));
    output.push_back(lo(arr, n, x));
    return output;
}



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends