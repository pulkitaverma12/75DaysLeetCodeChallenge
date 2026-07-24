class Solution {
public:
    bool isHappy(int num) {
        unordered_set<int> seen;
        while (num != 1 && seen.find(num) == seen.end()) {
            seen.insert(num);
            int sum = 0;
            while (num > 0) {
                int digit = num % 10;
                sum += digit * digit;
                num /= 10;
            }
            num = sum;
        }
        return num == 1;
    }
};