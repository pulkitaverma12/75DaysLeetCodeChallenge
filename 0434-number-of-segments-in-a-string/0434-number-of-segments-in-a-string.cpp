class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int ans = 0;
        int i = 0;
        while(i < s.length()){
            while(i < s.length() && s[i] == ' ') i++;
            while(i < s.length() && s[i] != ' ') {
                i++;
                count++;
            }
            if(count > 0) ans++;
            count = 0;
        }
        return ans;
    }
};