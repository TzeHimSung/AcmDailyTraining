class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for (auto i : s) {
            if (i == '(' || i == '{' || i == '[') {
                st.push(i);
                continue;
            }
            if (st.empty()) return false;
            if (st.top() == '(' && i != ')') return false;
            if (st.top() == '{' && i != '}') return false;
            if (st.top() == '[' && i != ']') return false;
            st.pop();
        }
        return st.empty();
    }
};