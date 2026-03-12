class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            int first = arr[i];
            int sec = tar - first;
            if(mp.find(sec)!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[sec]);
                break;
            }
            mp[first] = i;
        }
        return ans;
    }
};