class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long mod = 1e9 + 7;

        vector<vector<long>> maxProd(m, vector<long>(n));
        vector<vector<long>> minProd(m, vector<long>(n));

        maxProd[0][0] = minProd[0][0] = grid[0][0];

        // First row
        for(int j = 1; j < n; j++){
            maxProd[0][j] = minProd[0][j] = maxProd[0][j-1] * grid[0][j];
        }

        // First column
        for(int i = 1; i < m; i++){
            maxProd[i][0] = minProd[i][0] = maxProd[i-1][0] * grid[i][0];
        }

        // Fill DP
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                long val = grid[i][j];

                long a = maxProd[i-1][j] * val;
                long b = minProd[i-1][j] * val;
                long c = maxProd[i][j-1] * val;
                long d = minProd[i][j-1] * val;

                maxProd[i][j] = max({a, b, c, d});
                minProd[i][j] = min({a, b, c, d});
            }
        }

        long result = maxProd[m-1][n-1];

        if(result < 0) return -1;
        return result % mod;
    }
};