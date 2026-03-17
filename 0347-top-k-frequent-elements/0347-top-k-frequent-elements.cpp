class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    // Step 1: Count frequency
    for (int num : nums) {
        freq[num]++;
    }
    // Step 2: Bucket
    vector<vector<int>> bucket(nums.size() + 1);
    for (auto it : freq) {
        int num = it.first;
        int count = it.second;
        bucket[count].push_back(num);
    }
    // Step 3: Get top k
    vector<int> ans;
    for (int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--) {
        for (int num : bucket[i]) {
            ans.push_back(num);
            if (ans.size() == k) break;
        }
    }
    return ans;
   }
};