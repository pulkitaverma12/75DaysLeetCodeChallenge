class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low=0,high;
        double sum=0;
        double res=INT_MIN,avg=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        res=sum;
        int j=0;
        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
            sum-=nums[j];
            j++;
            res=max(res,sum);
        }
        return res/k;
    }
};