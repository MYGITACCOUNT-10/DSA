class Solution {
public:
    int numberOfSpecialChars(string word) {

        int count=0;

        vector<int>caps(26,-1);// storing the index of uppercase
        vector<int>small(26,-1);// storing the index of lower case

        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            int ascii=ch;

            if(ascii>=65 && ascii<=90)
            {
                int index=ch-'A';
                if(caps[index]==-1) caps[index]=i;
            }
            else
            {
                int index=ch-'a';
                small[index]=i;
            }
        }

        for(int i=0;i<26;i++)
        {
            if(caps[i]!=-1 && small[i]!=-1 && (caps[i]>small[i])) count++;
        }

        return count;
        
        
    }
};