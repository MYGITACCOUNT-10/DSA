class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // Check rows
        for (int row = 0; row < rows; row++) {
            vector<int> freq(10, 0);
            for (int col = 0; col < cols; col++) {
                if (board[row][col] != '.') {
                    int digit = board[row][col] - '0';
                    if (digit < 1 || digit > 9) return false;
                    freq[digit]++;
                    if (freq[digit] > 1) return false;
                }
            }
        }

        // Check columns
        for (int col = 0; col < cols; col++) {
            vector<int> freq(10, 0);
            for (int row = 0; row < rows; row++) {
                if (board[row][col] != '.') {
                    int digit = board[row][col] - '0';
                    if (digit < 1 || digit > 9) return false;
                    freq[digit]++;
                    if (freq[digit] > 1) return false;
                }
            }
        }

        // Check 3x3 sub-boxes
        for (int blockRow = 0; blockRow < 3; blockRow++) {
            for (int blockCol = 0; blockCol < 3; blockCol++) {
                vector<int> freq(10, 0);
                for (int r = blockRow * 3; r < blockRow * 3 + 3; ++r) {
                    for (int c = blockCol * 3; c < blockCol * 3 + 3; ++c) {
                        if (board[r][c] != '.') {
                            int digit = board[r][c] - '0';
                            if (digit < 1 || digit > 9) return false;
                            freq[digit]++;
                            if (freq[digit] > 1) return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
