class Solution {
public:
    long long maxHeight(long long time, int w) {
        long long left = 0, right = 1e6;
        long long ans = 0;
        while(left <= right) {
            long long mid = (left + right) / 2;
            long long needed = (long long)w * mid * (mid + 1) / 2;   
            if(needed <= time) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }   
        return ans;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0, right = 1e18;
        long long ans = right;
        while(left <= right) {
            long long mid = (left + right) / 2;
            long long total = 0;
            for(int w : workerTimes) {
                total += maxHeight(mid, w);
                if(total >= mountainHeight) break;
            }   
            if(total >= mountainHeight) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};