class Solution {
public:
    int findComplement(int num) {
        vector<int> v(32, 0);
        int i=0, sz = 0;
        while(num){
            v[i] = num%2;
            num /= 2;
            i++;
            sz++;
        }
        
        for(auto a: v) cout<<a<<" ";
        cout<<endl;
        
        
        for(int i=0; i<sz; i++){
            if(v[i]) v[i] = 0;
            else v[i] = 1;
        }
        
                for(auto a: v) cout<<a<<" ";
        cout<<endl;
        
        int ans = 0;
        for(int j = 0, i=0; j<32; j++, i++){
            ans += v[i]*pow(2, j);
        }
        
        return ans;
    }
};