class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        int n=points.size();
        int result=0;

        for(int i=0;i<n;i++)
        {
            //A point(candidate for upper-left)
            int x1=points[i][0];
            int y1=points[i][1];

            for(int j=0;j<n;j++)
            {   
                if(i==j) continue;
                //B point(candiadate for lower-right)
                int x2=points[j][0];
                int y2=points[j][1];

                if(x2>=x1 && y2<=y1)//condition for B is in the lower right of A
                {    
                    bool isInside=false;
                    for(int k=0;k<n;k++)
                    {
                        if(k==i || k==j) continue;

                        int x3=points[k][0];
                        int y3=points[k][1];

                        if(x3>=x1 && x3<=x2 &&  y3>=y2 && y3<=y1)
                        {
                            isInside=true;
                            break;
                        }
                    }

                    if(!isInside) result++;
                }
            }
        }

        return result;
        
    }
};