class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> diagonals;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                diagonals[i-j].push_back(grid[i][j]);
            }
        }

        // Since we are filtering the diagonals value on the basis of (i-j) value.
        // If (i-j)>=0 then it represents the bottom-left triangle (including the middle diagonal).
        // If (i-j)<0 then it represents the top-right triangle (excluding the middle diagonal).
        // let (i-j) ===> hash value

        for(auto& itr : diagonals) {
            int hash = itr.first;
            vector<int>& v = itr.second;  // Reference to modify in place
            
            if(hash >= 0) {
                // Bottom-left triangle: sort in non-increasing order (descending)
                sort(v.begin(), v.end(), greater<int>());
            } else {
                // Top-right triangle: sort in non-decreasing order (ascending)
                sort(v.begin(), v.end());
            }
        }

        // Rebuild the result matrix by placing sorted diagonal elements back
        vector<vector<int>> result(rows, vector<int>(cols));
        unordered_map<int, int> indices; // Track current index for each diagonal
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int hash = i - j;
                result[i][j] = diagonals[hash][indices[hash]++];
            }
        }
        
        return result;
    }
};