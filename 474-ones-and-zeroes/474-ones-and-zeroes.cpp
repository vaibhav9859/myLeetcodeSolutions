class Solution {
public:
int dp[601][101][101];
int findSize(vector<pair<int,int>>&vp,long long zeros,long long ones,int m,int n,int i)
{
    if(i>=vp.size())
        return 0;
    if(zeros>m || ones>n)
        return 0;
    int ans1=0,ans2=0,ans3=0;
    if(dp[i][zeros][ones]!=-1)
        return dp[i][zeros][ones];
    if(zeros+vp[i].first<=m && ones+vp[i].second<=n)
    {
         ans1=1+findSize(vp,zeros+vp[i].first,ones+vp[i].second,m,n,i+1);
         ans2= findSize(vp,zeros,ones,m,n,i+1);
    }
    else{
         ans3= findSize(vp,zeros,ones,m,n,i+1);
    }
    return dp[i][zeros][ones]=max({ans1,ans2,ans3});
    
}

int findMaxForm(vector<string>& strs, int m, int n) {
  int size=strs.size();
   vector<pair<int,int>>vp;
  for(int i=0;i<size;i++)
  {
      int sz=strs[i].size();
      int count0=0;
      int count1=0;
      for(int j=0;j<sz;j++)
      {
          if(strs[i][j]=='0')
              count0++;
          else{
              count1++;
          }
      }
      vp.push_back({count0,count1});
  }
 memset(dp,-1,sizeof(dp));
 return findSize(vp,0,0,m,n,0);
}
};