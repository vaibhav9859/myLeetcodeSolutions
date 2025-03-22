class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        // st.push(s[0]);
        int sz = s.size();

        for(int i=0; i<sz; i++){
            if(st.empty()) st.push(s[i]);
            else if(s[i] != st.top() and toupper(s[i]) == toupper(st.top())){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};