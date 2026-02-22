class Solution {
private:
string tobinary(int n)
{   
    string s;
    while(n>0)
    {
        int rem=n%2;
        n=n/2;
        s += to_string(rem);
    }

    reverse(s.begin(),s.end());

    return s;
}
public:
    int binaryGap(int n) {

        string b=tobinary(n);
        int prev_one = -1;
        int curr_one = -1;

        int dis = 0;

    for(int i = 0; i < b.size(); i++)
    {
        if(b[i] == '1')
        {
            prev_one = curr_one;
            curr_one = i;

            if(prev_one != -1)   // ensure two 1s exist
            dis = max(dis, curr_one - prev_one);
        }
    }

        return dis;
        
    }
};