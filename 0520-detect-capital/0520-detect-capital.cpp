class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        for(int i = 0 ;i < word.length(); i++){
            if(isupper(word[i])) cap++;
        }
        if(cap == 1 && isupper(word[0])) return true;
        else if(cap == 0) return true;
        else if(cap == word.length()) return true;
        return false; 
    }
};