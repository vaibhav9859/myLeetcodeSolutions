class Solution {
public:
    int arr[1002][1002];
    
    int longestCommonSubsequence(string &text1, string &text2, int i=0, int j=0) {
        if(i==text1.size() or j==text2.size()){
            return 0;
        }
        if(i==0 and j==0){
            memset(arr, -1, sizeof(arr));
        }
        
        if(arr[i][j] != -1) return arr[i][j];
        

        if(text1[i] == text2[j]){ 
            
            return arr[i][j] =  1 + longestCommonSubsequence(text1, text2, i+1, j+1);
        }
        
        return arr[i][j] = max(longestCommonSubsequence(text1, text2, i+1, j), longestCommonSubsequence(text1, text2, i, j+1) );
        

        
    }
};