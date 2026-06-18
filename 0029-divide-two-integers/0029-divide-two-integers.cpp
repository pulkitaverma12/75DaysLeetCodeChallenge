class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool isNegative = (dividend < 0) ^ (divisor < 0);

        long long n = labs(dividend);
        long long d = labs(divisor);
        long long ans = 0;

        int shift = 0;
        while (n >= (d << (shift + 1))) {
            shift++;
        }

        for (int i = shift; i >= 0; i--) {
            if (n >= (d << i)) {
                n -= (d << i);
                ans += (1LL << i); 
            }
        }

        return isNegative ? -ans : ans;
    }
};