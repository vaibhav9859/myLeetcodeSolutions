class Solution {
public:
    string longestPalindrome(string s) {
        /// O(n2) soution.. NOT DP
        string s1; string s2;
        for(int i=0; i<s.length(); i++){ s1.push_back('#'); s1.push_back(s[i]);}
        s1.push_back('#');
        
        int arr[s1.length()]; arr[0]=1;
        
        for(int i=1; i<s1.length(); i++){
            longest(s1, arr, i);
        }
        
            
        int max=arr[0], pos=0;
        for(int i=1; i<s1.length(); i++){
            if(arr[i]>max) {max=arr[i]; pos=i;}
        }
        for(int i=pos-(max/2); i<=pos+(max/2); i++) { if(s1[i]!='#') s2.push_back(s1[i]);  }
        return s2;
    }
    
    void longest(string &s1, int *arr, int i){
    int left, right; left=right=i; left--; right++; arr[i]=1;

    while(left>=0 && right<=s1.length()-1){
        if(s1[left]==s1[right]){
            arr[i] += 2; left--; right++; continue;
        }
        else break;
    }

}
};