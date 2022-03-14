class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m; 
        m['I'] = 1; m['V'] = 5; m['X'] = 10; m['L'] = 50;
        m['C'] = 100; m['D'] = 500; m['M'] = 1000;
        
        int ans = 0;
        
        for(int i=s.size()-2; i>=0; i--){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
            // cout<<ans<<" ";
        }
        
        ans += m[s[s.size()-1]];
        // cout<<ans<<endl;
        
        return ans;
    }
};