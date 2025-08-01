class Solution {
public:
    bool isPalindrome(string s) {
     transform(s.begin(), s.end(), s.begin(), ::tolower); 
     int j=0;
     for(int i=0;i<s.size();i++)
     {    if(isalnum(s[i])){
         s[j++]=s[i];}
     }
        int start=0;
        int end=j-1;//lenght of updated tsring without space  and ll lowercase

        while(start<=end)
        {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
};