// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int rowS = hospital.size(), colS = hospital[0].size();
        int ans = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<hospital.size(); i++){
            for(int j=0; j<hospital[0].size(); j++){
                if(hospital[i][j] == 2) q.push({i,j});
            }
        }
        
        if(q.empty()) return 0;
        q.push({-1, -1});
        
        while(!q.empty()){
            
            while(!q.empty() and q.front().first != -1){
                int curRow = q.front().first, curCol = q.front().second;
                q.pop();
                
                if(curRow-1>=0 and hospital[curRow-1][curCol] == 1) {q.push({curRow-1, curCol}); hospital[curRow-1][curCol] = 2;}
                if(curCol+1< colS and hospital[curRow][curCol+1] == 1) {q.push({curRow, curCol+1}); hospital[curRow][curCol+1] = 2;};
                if(curRow+1< rowS and  hospital[curRow+1][curCol] == 1){q.push({curRow+1, curCol}); hospital[curRow+1][curCol] = 2;};
                if(curCol-1 >=0 and hospital[curRow][curCol-1] == 1){ q.push({curRow, curCol-1}); hospital[curRow][curCol-1] = 2;}
                
            }

            
            if(!q.empty()) q.pop();
            if(!q.empty()){ q.push({-1, -1}); ans++;}
        }
        
        for(int i=0; i<hospital.size(); i++){
            for(int j=0; j<hospital[0].size(); j++){
                if(hospital[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends