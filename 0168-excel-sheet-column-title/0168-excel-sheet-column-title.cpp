class Solution {
public:
    string convertToTitle(int columnnumber) {
        string a = "";
        while(columnnumber > 0){
            columnnumber--;
            a += char('A' + columnnumber % 26);
            columnnumber /= 26;
        }
        reverse(a.begin(),a.end());
        return a;
    }
};