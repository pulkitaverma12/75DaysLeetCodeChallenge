class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // key value pair
        int n = nums.size();
        int prefixsum = 0;
        int count = 0;
        mp[0] = 1; // assume we've seen '0' once
        // this also means that at key=0, value=1

        for (int i = 0; i < n; i++) {
            prefixsum = prefixsum + nums[i]; // storing prefix sum
            if (mp.find(prefixsum - k) != mp.end()) {
                count = count + mp[prefixsum - k];
            }
            mp[prefixsum]++; // without this line, future elements won’t know
                             // this sum existed and you’ll miss subarrays
        }
        return count;
    }
};