class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        
        int i=0, count1=0, count2=0;
        while( i+1 < arr.size() and arr[i]<arr[i+1] ){ i++; count1++;}
         count1++;
        while( i+1 < arr.size() and arr[i]>arr[i+1] ) {i++;count2++;}
        count2++; i++;
        if(count1 <2 or count2<2 or i<arr.size()) return false;
        return true;
    }
};