class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {


        for(int i=0;i<(k/2);i++)
        {   
            vector<int>row_1;
            vector<int>row_2;

            int top=x+i;
            int bottom=x+(k-1)-i;

            //Storing the elements of rows in variables
            for(int j=y;j<(y+k);j++)
            {
                row_1.push_back(grid[top][j]);
                row_2.push_back(grid[bottom][j]);

            }
            swap(row_1,row_2);

            // write back to grid
            for(int j = 0; j < k; j++)
            {
                grid[top][y + j] = row_1[j];
                grid[bottom][y + j] = row_2[j];
            }


        }

        return grid;

        

        
    }
};