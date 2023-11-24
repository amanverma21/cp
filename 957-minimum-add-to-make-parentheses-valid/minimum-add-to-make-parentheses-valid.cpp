class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        for(int i=0; i<s.size(); i++){
            char ch= s[i];
            if(ch=='('){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    int top = st.top();
                    if(top=='('&& ch==')'){
                        st.pop();
                    }
                    else{
                        st.push(ch);
                    }
                }
                else{
                    st.push(ch);
                }
            }
        }
        return st.size();
    }
};