class Solution {
public:
    bool hasSameDigits(string s) {

        while(s.size()>2)
        {   
            string temp;
            for(int i=0;i<s.size()-1;i++)
            {
                int sum = (s[i] - '0') + (s[i + 1] - '0');
                char ch = (sum % 10) + '0';
                temp.push_back(ch);
            }
            s=temp;
        }

        return (s[0]==s[1])?true:false;
        
    }
};