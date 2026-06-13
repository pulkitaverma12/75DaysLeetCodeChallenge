class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i = 0;i<n+1;i++)
        {
            total+=i;
        }
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum+=nums[i];
        }
        return total - sum;
    }
};