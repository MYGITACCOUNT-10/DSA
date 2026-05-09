class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int rows=grid.size();
        int cols=grid[0].size();

        // int L=2*(rows-1)+2*(cols-1);
        // int k=k%L;
        //This is only correct for the outerlayer only....therefore we need to update the k for each layer.

        int left=0;
        int right=cols-1;
        int top=0;
        int bottom=rows-1;
        int layers=min(rows,cols)/2;

        for(int layer=0;layer<layers;layer++)
        {   
            //For outermost layer..layer = 0
            int top = layer;
            int left = layer;
            int bottom = rows - layer - 1;
            int right = cols - layer - 1;

            vector<int> v;

            // left column (top -> bottom-1)
            for(int i = top; i < bottom; i++)
            {
                v.push_back(grid[i][left]);
            }

            // bottom row (left -> right-1)
            for(int j = left; j < right; j++)
            {
                v.push_back(grid[bottom][j]);
            }

            // right column
            for(int i = bottom; i > top; i--)
            {
                v.push_back(grid[i][right]);
            }

            // top row (right -> left+1)
            for(int j = right; j > left; j--)
            {
                v.push_back(grid[top][j]);
            }

            //Rotation
            int len = v.size();
            int rotate = k % len;

            vector<int> temp(len);

            for(int i = 0; i < len; i++)
            {
                temp[i] = v[(i-rotate+len)%len];
            }

            //Reassign
            int c=0;
            // left column (top -> bottom-1)
            for(int i = top; i < bottom; i++)
            {
                grid[i][left]=temp[c];
                c++;
            }

            // bottom row (left -> right-1)
            for(int j = left; j < right; j++)
            {
                grid[bottom][j]=temp[c];
                c++;
            }

            // right column (bottom -> top+1)
            for(int i = bottom; i > top; i--)
            {
                grid[i][right]=temp[c];
                c++;
            }

            // top row (right -> left+1)
            for(int j = right; j > left; j--)
            {
                grid[top][j]=temp[c];
                c++;
            }


        }

        return grid;
        
    }
};