class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i = 0 ; i<tokens.size();i++)
        {
            if(tokens[i] == "+")
            {
                int p = st.top();
                st.pop();
                int q = st.top();
                st.pop();
                int sum = p+q;
                st.push(sum);
            }
            else if(tokens[i]=="-")
            {
                int p = st.top();
                st.pop();
                int q = st.top();
                st.pop();
                int sum = q-p;
                st.push(sum);
            }
            else if(tokens[i]=="*")
            {
                int p = st.top();
                st.pop();
                int q = st.top();
                st.pop();
                int sum = p*q;
                st.push(sum);
            }
            else if(tokens[i]=="/")
            {
                int p = st.top();
                st.pop();
                int q = st.top();
                st.pop();
                int sum = q/p;
                st.push(sum);
            }
            else
            {
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};
