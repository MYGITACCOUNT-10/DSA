class Solution {
public:
    int romanToInt(string s) {
        int value=0;
         unordered_map<char, int> roman = {
            {'I',1}, {'V',5}, {'X',10}, {'L',50},
            {'C',100}, {'D',500}, {'M',1000}
        };

        int i=0;
       while(i<s.size())
        {   
            int curr=roman[s[i]];
            int next=roman[s[i+1]];
            if(curr<next)
            {
                value+=(next-curr);
                i=i+2;
            }
            else{
                value+=curr;
                i++;
            }

        }

        return value;
        
    }
};