class Solution {
public:
    string smallestPalindrome(string st) {
        int n = st.length();
        int m = n/2;
        sort(begin(st),begin(st) + m);
        for(int i = 0;i<m;i++){
            st[n - i -1] = st[i];
        }
        return st;
    }
};