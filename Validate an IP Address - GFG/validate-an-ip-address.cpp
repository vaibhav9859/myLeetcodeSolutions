// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            int dots = 3; int it = 0;
            while(it < s.size()){
                string curOctet;
                
                while(it<s.size() and s[it] != '.'){
                    if(s[it]<'0' or s[it] > '9') return 0;
                    curOctet += s[it]; it++;
                    if(curOctet.size() > 3) return 0;
                }
                
                if(s[it] == '.') dots--;
                it++; 
                if(dots < 0) return 0;
                if(curOctet.size() > 1 and curOctet[0] == '0'  or (curOctet.size() < 1)) return 0;
                
                int curVal = stoi(curOctet);
                
                if(curVal >= 0 and curVal <= 255) continue;
                else return 0;
                
            
            }
            
            if(dots != 0) return 0;
            return 1;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends