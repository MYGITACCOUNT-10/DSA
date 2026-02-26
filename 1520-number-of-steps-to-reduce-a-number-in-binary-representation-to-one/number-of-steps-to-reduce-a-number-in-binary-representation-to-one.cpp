class Solution {
public:
    int numSteps(string s) {

        int steps=0;
        while(s!="1")
        {
            //IF ITS EVEN
            if(s.back()=='0')
            {
                s.pop_back();
            }

            //IF ITS ODD then add 1 in the last place
            else
            {
                int i=s.size()-1;

                while(i>=0 && s[i]=='1')
                {
                    s[i]='0';
                    i--;
                }

                if(i>=0) s[i]='1';
                else s='1'+s; //Since we have come to the leftmost position and i is negative
            }

            steps++;
        }
        return steps;
        
    }
};