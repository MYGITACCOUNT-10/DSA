class Solution {
public:
   int minimumArea(vector<vector<int>>& grid) {
    int min_x = INT_MAX, max_x = -1;
    int min_y = INT_MAX, max_y = -1;
    
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == 1) {
                min_x = min(min_x, i);
                max_x = max(max_x, i);
                min_y = min(min_y, j);
                max_y = max(max_y, j);
            }
        }
    }
    
    return (max_x - min_x + 1) * (max_y - min_y + 1);
}
};