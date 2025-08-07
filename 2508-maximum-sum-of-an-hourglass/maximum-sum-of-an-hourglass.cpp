class Solution {
int hourglass(int start_row, int start_col, vector<vector<int>>& grid) {
    int sum = 0;
    
    // Top row
    sum += grid[start_row][start_col] + grid[start_row][start_col + 1] + grid[start_row][start_col + 2];
    
    // Middle element
    sum += grid[start_row + 1][start_col + 1];
    
    // Bottom row
    sum += grid[start_row + 2][start_col] + grid[start_row + 2][start_col + 1] + grid[start_row + 2][start_col + 2];
    
    return sum;
}
public:
    int maxSum(vector<vector<int>>& grid) {

        int rows=grid.size();
        int cols=grid[0].size();
        int result=INT_MIN;

        for(int i=0;i<=rows-3;i++)
        {
            for(int j=0;j<=cols-3;j++)
            {
                result=max(result,hourglass(i,j,grid));
            }
        }

        return result;

        
        
    }
};