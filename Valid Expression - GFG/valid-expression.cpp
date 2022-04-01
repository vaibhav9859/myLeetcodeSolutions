// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}// } Driver Code Ends


bool valid(string s)
{
    // code here
    int cp1 = 0, cp2 = 0, cp3 = 0;
    
    for(int i=0; i<s.size(); i++){
        if(cp1<0 or cp2<0 or cp3<0) return false;
        
        if(s[i] == '(') cp1++;
        else if(s[i] == '[') cp2++;
        else if(s[i] == '{') cp3++;
        else if(s[i] == ')') cp1--;
        else if(s[i] == ']') cp2--;
        else if(s[i] == '}') cp3--;
    }
    
    if(cp1 != 0 or cp2 != 0 or cp3 != 0) return false;
    return true;
}