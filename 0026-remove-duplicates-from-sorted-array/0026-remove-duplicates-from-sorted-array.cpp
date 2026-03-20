class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int j = 1;
        for (int k = 1; k < nums.size(); k++) {
            if (nums[k] != nums[j - 1]) {
                nums[j] = nums[k];
                j++;
            }
        }
        return j;        
    }
};