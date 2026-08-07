class Solution {
public:
    int A, B, C, D;
    int dimA, dimB, dimC, dimD;
    vector<int> minCnt;
    int dc[10][4] = {
        {0,0,0,0},{0,0,0,0},{1,0,0,0},{0,1,0,0},{2,0,0,0},
        {0,0,1,0},{1,1,0,0},{0,0,0,1},{3,0,0,0},{0,2,0,0}
    };

    inline int idx(int e2, int e3, int e5, int e7) {
        return ((e2 * dimB + e3) * dimC + e5) * dimD + e7;
    }

    string buildSuffix(int e2, int e3, int e5, int e7, int L) {
        string s(L, '1');
        for (int pos = 0; pos < L; pos++) {
            int remainingPositions = L - pos - 1;
            for (int d = 1; d <= 9; d++) {
                int ne2 = max(0, e2 - dc[d][0]);
                int ne3 = max(0, e3 - dc[d][1]);
                int ne5 = max(0, e5 - dc[d][2]);
                int ne7 = max(0, e7 - dc[d][3]);
                if (minCnt[idx(ne2, ne3, ne5, ne7)] <= remainingPositions) {
                    s[pos] = '0' + d;
                    e2 = ne2; e3 = ne3; e5 = ne5; e7 = ne7;
                    break;
                }
            }
        }
        return s;
    }

    string smallestNumber(string num, long long t) {
        A = B = C = D = 0;
        while (t % 2 == 0) { t /= 2; A++; }
        while (t % 3 == 0) { t /= 3; B++; }
        while (t % 5 == 0) { t /= 5; C++; }
        while (t % 7 == 0) { t /= 7; D++; }
        if (t != 1) return "-1";

        dimA = A + 1; dimB = B + 1; dimC = C + 1; dimD = D + 1;
        minCnt.assign((long long)dimA * dimB * dimC * dimD, 0);

        for (int e2 = 0; e2 < dimA; e2++) {
            for (int e3 = 0; e3 < dimB; e3++) {
                for (int e5 = 0; e5 < dimC; e5++) {
                    for (int e7 = 0; e7 < dimD; e7++) {
                        if (e2 == 0 && e3 == 0 && e5 == 0 && e7 == 0) continue;
                        int best = INT_MAX;
                        for (int d = 2; d <= 9; d++) {
                            int ne2 = max(0, e2 - dc[d][0]);
                            int ne3 = max(0, e3 - dc[d][1]);
                            int ne5 = max(0, e5 - dc[d][2]);
                            int ne7 = max(0, e7 - dc[d][3]);
                            if (ne2 == e2 && ne3 == e3 && ne5 == e5 && ne7 == e7) continue;
                            int val = minCnt[idx(ne2, ne3, ne5, ne7)];
                            if (val < best) best = val;
                        }
                        minCnt[idx(e2, e3, e5, e7)] = best + 1;
                    }
                }
            }
        }

        int n = num.size();
        vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        bool zeroFree = true;
        int firstZero = n;
        for (int i = 0; i < n; i++) {
            int d = num[i] - '0';
            if (d == 0) { zeroFree = false; if (firstZero == n) firstZero = i; }
            p2[i + 1] = p2[i] + dc[d][0];
            p3[i + 1] = p3[i] + dc[d][1];
            p5[i + 1] = p5[i] + dc[d][2];
            p7[i + 1] = p7[i] + dc[d][3];
        }

        if (zeroFree && p2[n] >= A && p3[n] >= B && p5[n] >= C && p7[n] >= D) {
            return num;
        }

        int maxI = min(n - 1, firstZero);
        for (int i = maxI; i >= 0; i--) {
            int startDigit = (num[i] - '0') + 1;
            for (int d = startDigit; d <= 9; d++) {
                int e2 = p2[i] + dc[d][0];
                int e3 = p3[i] + dc[d][1];
                int e5 = p5[i] + dc[d][2];
                int e7 = p7[i] + dc[d][3];
                int rA = max(0, A - e2), rB = max(0, B - e3), rC = max(0, C - e5), rD = max(0, D - e7);
                int suffixLen = n - 1 - i;
                if (minCnt[idx(rA, rB, rC, rD)] <= suffixLen) {
                    string result = num.substr(0, i);
                    result.push_back('0' + d);
                    result += buildSuffix(rA, rB, rC, rD, suffixLen);
                    return result;
                }
            }
        }

        int M = minCnt[idx(A, B, C, D)];
        int L = max(n + 1, M);
        return buildSuffix(A, B, C, D, L);
    }
};