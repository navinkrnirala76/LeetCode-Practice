class Solution {
    template<typename Fn>
    void eval(stack<int64_t>& st, Fn fn) {
        int64_t rhs = st.top(); st.pop();
        int64_t lhs = st.top(); st.pop();
        st.push(fn(lhs, rhs));
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int64_t> st;
        for (const string& tk : tokens) {
            if (tk == "+") {
                eval(st, [](int64_t lhs, int64_t rhs){ return lhs+rhs;});
            } else if (tk == "-") {
                eval(st, [](int64_t lhs, int64_t rhs){ return lhs-rhs;});
            } else if (tk == "*") {
                eval(st, [](int64_t lhs, int64_t rhs){ return lhs*rhs;});
            } else if (tk == "/") {
                eval(st, [](int64_t lhs, int64_t rhs){ return lhs/rhs;});
            } else {
                st.push(stoi(tk));
            }
        }
        return st.top();
    }
};
