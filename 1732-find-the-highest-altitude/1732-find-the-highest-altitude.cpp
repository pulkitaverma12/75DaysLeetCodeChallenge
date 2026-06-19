class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, mx = 0;
        for (auto x : gain) mx = max(mx, sum += x);
        return mx;
    }
};