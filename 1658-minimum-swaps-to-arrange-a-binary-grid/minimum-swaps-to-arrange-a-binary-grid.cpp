class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        int n=grid.size();
        vector<int> last_one(n);//Storing the last occuring 1 in ith row 

        for(int i=0;i<grid.size();i++)
        {   
            int latest_loc=-1;
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    latest_loc=j;
                }
            }

            last_one[i]=latest_loc;
        }

        int swaps=0;
        //Row i must have no 1 after column i..after col i..it should only contain 0.

        //For each row position i, we need a row whose rightmost 1 index ≤ i.
        for(int i=0;i<n;i++)
        {   
            int j=-1;
            for(int row=i;row<last_one.size();row++)
            {// We must pick the first valid row, otherwise swaps increase.
                if(last_one[row]<=i)
                {
                    j=row;
                    break;
                }
            }
            if(j==-1) return -1;

            while(j!=i)
            {
                swap(last_one[j],last_one[j-1]);
                swaps++;
                j--;
            }
        }

        return swaps;
        


        
    }
};