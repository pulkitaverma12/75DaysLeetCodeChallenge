class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int> s;
        for(int i = 0;i<m;i++){
            for(int j = 0 ;j<n;j++){
                s.insert(grid[i][j]);
                for(int size = 1 ; ;size++){
                    if(i+2*size>=m || j-size<0 || j+size>=n)
                        break;
                    int sum = 0;
                    int x = i , y = j;
                    // top -> k
                    for(int k =0;k<size;k++){
                        sum += grid[x+k][y+k];
                    }
                    // right-> bottom
                    for(int k = 0;k<size;k++){
                        sum += grid[x+size+k][y+size-k];
                    }
                    // bottom -> k
                    for(int k =0;k<size;k++){
                        sum += grid[x+2*size-k][y-k];
                    }
                    // left -> top
                    for(int k = 0;k<size;k++){
                        sum += grid[x+size-k][y-size+k];
                    }
                    s.insert(sum);
                }
            }
        }
        vector<int> ans;
        for(auto it = s.rbegin(); it !=s.rend() && ans.size()<3; it++){
            ans.push_back(*it);
        }
        return ans;
    }
};