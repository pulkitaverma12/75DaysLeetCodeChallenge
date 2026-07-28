class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int m = n/2;
        sort(begin(s),begin(s) + m);
        for(int i = 0;i<m;i++){
            s[n - i -1] = s[i];
        }
        return s;
    }
};