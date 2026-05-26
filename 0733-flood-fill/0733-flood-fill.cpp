class Solution {

private:

    void BFS(int row, int col, int m, int n, int color,
             vector<vector<int>>& image,
             vector<vector<int>>& visited) {

        queue<pair<int, int>> qe;

        qe.push({row, col});

        visited[row][col] = 1;

        int prevColor = image[row][col];

        image[row][col] = color;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!qe.empty()) {

            int r = qe.front().first;
            int c = qe.front().second;

            qe.pop();

            for (int i = 0; i < 4; i++) {

                int neighrow = r + delrow[i];
                int neighcol = c + delcol[i];

                if (neighrow >= 0 && neighcol >= 0 &&
                    neighrow < m && neighcol < n &&
                    !visited[neighrow][neighcol] &&
                    image[neighrow][neighcol] == prevColor) {

                    qe.push({neighrow, neighcol});

                    visited[neighrow][neighcol] = 1;

                    image[neighrow][neighcol] = color;
                }
            }
        }
    }

    void DFS(int row, int col, int m, int n, int color,
             vector<vector<int>>& image,
             vector<vector<int>>& visited) {

        visited[row][col] = 1;

        int prevColor = image[row][col];

        image[row][col] = color;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {

            int neighrow = row + delrow[i];
            int neighcol = col + delcol[i];

            if (neighrow >= 0 && neighrow < m &&
                neighcol >= 0 && neighcol < n &&
                !visited[neighrow][neighcol] &&
                image[neighrow][neighcol] == prevColor) {

                DFS(neighrow, neighcol, m, n,
                    color, image, visited);
            }
        }
    }

public:

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> visited(m,
                                    vector<int>(n, 0));

        // BFS Traversal
        // BFS(sr, sc, m, n, color, image, visited);

        // DFS Traversal
        DFS(sr, sc, m, n, color, image, visited);

        return image;
    }
};