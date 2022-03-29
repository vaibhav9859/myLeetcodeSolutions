// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<string>  spaceString(char str[]);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[10000];
        cin>>str;
        vector<string> vec = spaceString(str);
        for(string s: vec){
            cout<<s<<"$";
        }
        cout<<endl;
    }

}
// } Driver Code Ends


/*You have to complete this function*/

void helper(char str[], int sz, int i, string curStr, vector<string> &output){
    if(i==sz){
        
        // if(!curStr.empty() and curStr[curStr.size()-1] == ' ') curStr.pop_back();
        // if(s.find(curStr) != s.end()) return;
        output.push_back(curStr); 
        // s.insert(curStr);
        return;
    }
    
    helper(str, sz, i+1, curStr + str[i], output);
    if(i!=sz-1) helper(str, sz, i+1, curStr + str[i]+" ", output);
}

vector<string>  spaceString(char str[])
{
//Your code here
    // set<string> s;
    vector<string> output;
    helper(str, strlen(str), 0, "", output);
    
    return output;
}

