class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n1=cost.size();
        for(int i=2;i<n1;i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[n1-1],cost[n1-2]);
    }
};