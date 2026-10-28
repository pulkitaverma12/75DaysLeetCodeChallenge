class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> board(m, vector<char>(n));

        for (int i = 0; i < n; i++) {
            board[0][i] = '.';
        }

        for (int i = 0; i < m; i++) {
            board[i][n - 1] = '.';
        }

        vector<string> result(m);

        for (int i = 0; i < m; i++) {
            string res = "";

            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    board[i][j] = '#';
                }

                res += board[i][j];
            }

            result[i] = res;
        }

        return result;
    }
};