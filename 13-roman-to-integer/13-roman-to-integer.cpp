class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m; 
        m['I'] = 1; m['V'] = 5; m['X'] = 10; m['L'] = 50;
        m['C'] = 100; m['D'] = 500; m['M'] = 1000;
        
        int ans = 0;
        
        for(int i=0; i<s.size(); i++){
            if(i+1 <s.size() and s.substr(i, 2) == "IV"){
                ans += 4; i++; continue;
            }
            if(i+1 <s.size() and s.substr(i, 2) == "IX"){
                ans += 9; i++; continue;
            }
            if(i+1 <s.size() and s.substr(i, 2) == "XL"){
                ans += 40; i++; continue;
            }
            if(i+1 <s.size() and s.substr(i, 2) == "XC"){
                ans += 90; i++; continue;
            }
            if(i+1 <s.size() and s.substr(i, 2) == "CD"){
                ans += 400; i++; continue;
            }
            if(i+1 <s.size() and s.substr(i, 2) == "CM"){
                ans += 900; i++; continue;
            }
            ans += m[s[i]];
        }
        
        return ans;
    }
};