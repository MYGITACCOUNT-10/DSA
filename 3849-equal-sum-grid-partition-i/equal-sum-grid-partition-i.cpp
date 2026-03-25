class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<long long> prefix_rows(rows, 0);

        prefix_rows[0] = accumulate(grid[0].begin(), grid[0].end(), 0LL);

        for(int i = 1; i < rows; i++) {
            long long sum = accumulate(grid[i].begin(), grid[i].end(), 0LL);
            prefix_rows[i] = prefix_rows[i-1] + sum;
        }

        long long total = prefix_rows[rows-1];

        // Horizontal cut
        for(int i = 0; i < rows-1; i++) {
            if(prefix_rows[i] == total - prefix_rows[i])
                return true;
        }

        // Vertical cut
        vector<long long> prefix_cols(cols, 0);

        for(int j = 0; j < cols; j++) {
            long long colSum = 0;
            for(int i = 0; i < rows; i++) {
                colSum += grid[i][j];
            }

            if(j == 0)
                prefix_cols[j] = colSum;
            else
                prefix_cols[j] = prefix_cols[j-1] + colSum;
        }

        for(int j = 0; j < cols-1; j++) {
            if(prefix_cols[j] == total - prefix_cols[j])
                return true;
        }

        return false;
    }
};