class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        for(int i = 0 ;i < word.length(); i++){
            if(isupper(word[i])) cap++;
        }
        // agar vo capital hone ka count 1 hai or 1st index me hi cap hai baki small toh
        if(cap == 1 && isupper(word[0])) return true;  
        // agar capital count 0 hai or small hogya sb 
        else if(cap == 0) return true;
        // agar captial count word ke length jitna hai matlab sab capital
        else if(cap == word.length()) return true;
        return false; 
    }
};