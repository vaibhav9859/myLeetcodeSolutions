class Solution {
public:
    int countSubstrings(string s) {
        int lptr = 0, rptr = 0;
        int n = s.size();
        int ans = 0;
        // compute the even string 
        for(int i = 0;i<n;i++)
        {
            lptr = i;
            rptr = i;
            while(lptr >= 0 && rptr < n)
            {
                if(s[lptr] == s[rptr])
                    ans+=1;
                else
                    break;
                lptr-=1;
                rptr+=1;
            }
        }
       // cout<<ans<<"\n";
        // compute the odd string
        for(int i  = 0;i<n-1;i++)
        {
            lptr = i;
            rptr = i+1;
            while(lptr >= 0 && rptr < n)
            {
                if(s[lptr] == s[rptr])
                    ans+=1;
                else
                    break;
                lptr-=1;
                rptr+=1;
            }
        }
        return ans;
    }
};