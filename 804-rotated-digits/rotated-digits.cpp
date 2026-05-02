class Solution {
public:
    int rotatedDigits(int n) {

        unordered_map<int,int> rotate;

        rotate[0] = 0;
        rotate[1] = 1;
        rotate[2] = 5;
        rotate[5] = 2;
        rotate[6] = 9;
        rotate[8] = 8;
        rotate[9] = 6;
        
        vector<bool> r(n + 1, false);   //size n+1
        int count=0;

        for(int i = 1; i <= n; i++)
        {   
            string s=to_string(i);
            string rotated="";
            bool valid = true;         

            for(int j=0;j<s.size();j++)
            {
                int digit=s[j]-'0';
                if(rotate.find(digit)==rotate.end())
                {
                    valid=false;
                    break;
                }
                rotated+=char(rotate[digit]+'0');
            }

            if(valid)
            {
                int new_num=stoi(rotated);
                if(new_num!=i)
                {
                    count++;
                }
            }
        }

        return count;
    }
};