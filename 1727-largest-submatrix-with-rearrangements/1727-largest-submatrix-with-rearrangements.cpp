class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n,0);
        int maxArea = 0;
        for(int i = 0 ; i<m; i++){
            for(int j = 0; j< n ;j++){
                if(matrix[i][j] == 0){
                    height[j] = 0;
                }
                else{
                    height[j] += 1;
                }
            }
            vector<int> sorth = height;
            sort(sorth.begin(), sorth.end(), greater<int>());
            for(int j = 0; j < n; j++) {
                maxArea = max(maxArea, sorth[j] * (j + 1));
            }
        }
        return maxArea;
    }
};