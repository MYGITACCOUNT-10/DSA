class Solution {
void transpose(vector<vector<int>>&mat)
{
    int n=mat.size();

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

}

void reverse(vector<vector<int>>&mat)
{   
    int n=mat.size();
    for(int i=0;i<n;i++)
    {
        vector<int>&row=mat[i];
        std::reverse(row.begin(),row.end());
        mat[i]=row;
    }

}
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int cnt=4;//Maximum we can rotate a matrix 4 times and then we get the same matrix
        //bool flag=true;
        while(cnt--)
        {
            transpose(mat);
            reverse(mat);

            if(mat==target) return true;
        }
       

        
        return false;


        
    }
};