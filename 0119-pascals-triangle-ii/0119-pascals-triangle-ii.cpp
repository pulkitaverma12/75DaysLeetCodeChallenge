class Solution {
public:
    vector<int> getRow(int rowindex) {
        vector<int> row(rowindex + 1,1);
        for(int i = 0;i < rowindex;i++){
            for(int j = i; j > 0 ;j--){
                row[j] = row[j] + row[j-1];
            }
        }
        return row;
    }
};