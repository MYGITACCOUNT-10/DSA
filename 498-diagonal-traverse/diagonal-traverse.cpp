class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return {};
        }

        int rows = mat.size();
        int cols = mat[0].size();

        //Initialize the vector with the correct size
        vector<vector<int>> diagonals(rows + cols - 1);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                diagonals[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> result;
        for (int i = 0; i < diagonals.size(); i++) {
           
            if (i % 2 == 0) {
                reverse(diagonals[i].begin(), diagonals[i].end());
            }

            for (int j = 0; j < diagonals[i].size(); j++) {
                result.push_back(diagonals[i][j]);
            }
        }

        return result;
    }
};