class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int sz = s.size(); int curCount = 0; char curEle;
        string output;
        
        for(int i=0; i<sz; i++){
            if(st.empty()){
                curEle = s[i]; curCount = 1; st.push({curEle, 0});
            }
            else{
                if(curEle == s[i]){
                    curCount++; st.push({s[i], 0});
                }
                else{
                    st.push({'A', curCount});
                    // cout<<(char)(curCount + '0')<<endl;
                    curEle = s[i]; curCount = 1; st.push({curEle, 0});
                    
                    
                }
            }
            
            if(curCount == k){
                while(!st.empty() and curCount != 0){
                    st.pop(); curCount--;
                }
                if(!st.empty()){
                    curCount = st.top().second; st.pop();
                    curEle = st.top().first;
                }
            }
        }
        
        while(!st.empty()){
            if(st.top().first == 'A');
            else output += st.top().first; 
            
            st.pop();
        }
        
        reverse(output.begin(), output.end());
        
        return output;
    }
};