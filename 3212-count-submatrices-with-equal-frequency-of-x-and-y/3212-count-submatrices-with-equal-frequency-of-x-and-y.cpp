class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prefixX(m+1, vector<int>(n+1, 0));
        vector<vector<int>> prefixY(m+1, vector<int>(n+1, 0));
        // build prefix
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                prefixX[i+1][j+1] = prefixX[i][j+1] + prefixX[i+1][j] - prefixX[i][j];
                prefixY[i+1][j+1] = prefixY[i][j+1] + prefixY[i+1][j] - prefixY[i][j];
                if(grid[i][j] == 'X') prefixX[i+1][j+1]++;
                if(grid[i][j] == 'Y') prefixY[i+1][j+1]++;
            }
        }
        int count = 0;
        // check all (0,0 → i,j)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int x = prefixX[i+1][j+1];
                int y = prefixY[i+1][j+1];

                if(x == y && x > 0){
                    count++;
                }
            }
        }
        return count;
    }
};