class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> digit;
        while(n>0){
            digit.push_back(n % 10);
            n /= 10;
        }
        reverse(digit.begin(),digit.end());
        int sum = 0;
        int sign = 1;
        for(int d : digit){
            sum += d * sign;
            sign *= -1;
        }
    return sum;
    }
};