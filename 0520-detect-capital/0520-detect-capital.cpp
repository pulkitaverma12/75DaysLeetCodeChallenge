class Solution {
public:
    bool detectCapitalUse(string word) {
        bool iscap = true;
        bool issmall = true;
        for(int i = 0; i < word.size(); i++) {
            if(islower(word[i])) {
                iscap = false;
            }
            if(isupper(word[i])) {
                issmall = false;
            }
        }
        bool firstCapital = isupper(word[0]);
        for(int i = 1; i < word.size(); i++) {
            if(isupper(word[i])) {
                firstCapital = false;
            }
        }
        if(iscap || issmall || firstCapital) {
            return true;
        }
        return false;
    }
};