// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int mid, int h)
    {
        int sz = h-l+1;
        int temp[sz];
        int i, j, k;
        for(i=l, j = mid+1, k =0; i<=mid and j<=h; k++){
            if(arr[i]<arr[j]){
                temp[k] = (arr[i]); i++;
            }
            else{
                temp[k]=(arr[j]); j++;
            }
        }
    
        while(i<=mid){
            temp[k]=(arr[i]); i++; k++;
        }
    
        while(j<=h){
            temp[k]=(arr[j]); j++; k++;
        }
    
    
        for(int i=0, k=l; i<sz and k<=h; i++, k++){
            arr[k] = temp[i];
        }


    }
    public:
    void mergeSort(int arr[], int l, int h)
    {
        if(l>=h) return;
        int mid = (l+h)/2;
    
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
    
        merge(arr, l, mid, h);
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends