class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int neg=0;
        for(int row=0;row<grid.size();row++)
        {
            int idx = grid[row].rend() - upper_bound(grid[row].rbegin(), grid[row].rend(), -1);
            //upperbound gives the first element greater than -1..
            //searches for first posotive element in reverse order..
            neg+=(grid[row].size()-idx);
        }
        return neg;
        
    }
};