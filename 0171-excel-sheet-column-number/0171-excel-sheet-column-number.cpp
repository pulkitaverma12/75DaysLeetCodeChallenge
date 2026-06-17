class Solution {
public:
    int titleToNumber(string columntitle) {
        int a = 0;
        for(char ch : columntitle){
            a = a * 26 + (ch - 'A' + 1);
        }
        return a;
    }
};