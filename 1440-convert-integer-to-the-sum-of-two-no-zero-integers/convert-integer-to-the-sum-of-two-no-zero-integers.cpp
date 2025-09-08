class Solution {
private:
//Tells that whther the number contain 0 or not.
//True->we the number doesn't ontain 0 else ->False.
bool zero(int x)
{
    bool flag=true;//Initially we assume that x doesn't contain 0 digit in it.

    while(x>0)
    {
        int last=x%10;
        if(last==0)
        {   
            flag=false;
            break;
        }
        x=x/10;

    }
    
    return flag;
}
public:
    vector<int> getNoZeroIntegers(int n) {
        
        vector<int>ans;
        //Since min value of n is 2.
        //Therefore we want a and b such that a+b=n and (a&b) doesnt contain any 0 digit in them.
        for(int i=1;i<(n);i++)
        {
            int a=i;
            int b=n-i;

            if(zero(a) && zero(b))
            {   
                ans.push_back(a);
                ans.push_back(b);
                break;
              
            }
        }

        return ans;
        
        
    }
};