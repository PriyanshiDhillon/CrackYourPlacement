class Solution {
public:
    void makeZero(vector<vector<int>>& matrix, int row, int column){
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < n; i++) {
            matrix[row][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            matrix[i][column] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeroPositions;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0) {
                    zeroPositions.push_back({i, j});
                }
            }
        }
        for (const auto& pos : zeroPositions) {
            makeZero(matrix, pos.first, pos.second);
        }
    }
};