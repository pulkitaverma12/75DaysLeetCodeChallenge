class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map;
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else if (map.count(c)) {
                if (st.empty() || st.top() != map[c]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};