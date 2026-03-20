class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        for(int i = 0; i <= m - k; i++) {
            for(int j = 0; j <= n - k; j++) {
                set<int> st;
                // collect k x k elements
                for(int x = i; x < i + k; x++) {
                    for(int y = j; y < j + k; y++) {
                        st.insert(grid[x][y]);
                    }
                }
                // convert to vector
                vector<int> v(st.begin(), st.end());
                // if only 1 unique element → answer = 0
                if(v.size() <= 1) {
                    ans[i][j] = 0;
                    continue;
                }
                // find minimum difference
                int mini = INT_MAX;
                for(int p = 1; p < v.size(); p++) {
                    mini = min(mini, v[p] - v[p - 1]);
                }       
                ans[i][j] = mini;
            }
        }      
        return ans;
    }
};