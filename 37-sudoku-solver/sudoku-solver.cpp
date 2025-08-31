class Solution {
private:
bool solve(vector<vector<char>>&board)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')
            {
                for(char d= '1';d<='9';d++)
                {
                    if(isValid(board,i,j,d))
                    {
                        board[i][j]=d;//DO
                        if(solve(board)==true)
                        {
                            return true;//EXPLORE
                        }
                        board[i][j]='.';//UNDO

                    }
                }
                return false;//NOT ABLE TO RETURN ANY CHARACTERS
            }
        }
    }

    return true;//ALL THE CELLS WERE FILLED BY DIGIT..THEREFORE WE DIDN'T WENT IN IF LOOOP
}


bool isValid(vector<vector<char>>&board,int row,int col,char d)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==d) return false;//ROW CHECK
        if(board[i][col]==d) return false;//COLUMN CHECK
    }

    int start_i=(row/3)*3;
    int start_j=(col/3)*3;

    for(int k=0;k<3;k++)
    {
        for(int l=0;l<3;l++)
        {
            if(board[start_i+k][start_j+l]==d) return false;
        }
    }

    return true;//AGAR EK BHI CASE MATCH NHI HUA HAI
}
public:
    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
        
    }
};