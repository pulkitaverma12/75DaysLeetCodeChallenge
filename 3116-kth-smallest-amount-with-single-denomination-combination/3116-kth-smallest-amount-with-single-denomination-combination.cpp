class Solution {
public:
    using int64 = long long;
    using i128 = __int128_t;

    long long gcdll(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcmLimit(long long a, long long b, long long limit) {
        long long g = gcdll(a, b);
        i128 res = (i128)(a / g) * b;
        if (res > limit) return limit + 1;
        return (long long)res;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        coins.erase(unique(coins.begin(), coins.end()), coins.end());

        // Remove redundant denominations.
        vector<long long> c;
        for (int x : coins) {
            bool keep = true;
            for (long long y : c) {
                if (x % y == 0) {
                    keep = false;
                    break;
                }
            }
            if (keep) c.push_back(x);
        }

        int n = c.size();

        auto count = [&](long long x) {
            long long ans = 0;
            int total = 1 << n;

            for (int mask = 1; mask < total; mask++) {
                long long l = 1;
                bool ok = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        l = lcmLimit(l, c[i], x);
                        if (l > x) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (!ok) continue;

                if (__builtin_popcount(mask) & 1)
                    ans += x / l;
                else
                    ans -= x / l;
            }
            return ans;
        };

        long long lo = 1, hi = 1;
        while (count(hi) < k) hi <<= 1;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};