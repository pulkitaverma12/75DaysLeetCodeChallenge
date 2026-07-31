class Solution {
public:
    string finalString(string s) {
        string a = "";
        for(char ch : s){
            if(ch == 'i'){
                reverse(a.begin(),a.end());
                continue;
            }
            else{
                a += ch;
            }
        }
        return a;
    }
};