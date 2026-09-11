class Solution {
public:
    int totalNumbers(vector<int>& digit) {
        set<int> numbers;
        for(int i = 0; i < digit.size(); i++) {
            // last digit must be even
            if(digit[i] % 2 != 0)
                continue;
            for(int j = 0; j < digit.size(); j++) {
                // first digit cannot be 0
                if(digit[j] == 0 || j == i)
                    continue;
                for(int k = 0; k < digit.size(); k++) {
                    // same index cannot be reused
                    if(k == i || k == j)
                        continue;

                    int num = digit[j] * 100 + digit[k] * 10 + digit[i];
                    numbers.insert(num);
                }
            }
        }
        return numbers.size();
    }
};