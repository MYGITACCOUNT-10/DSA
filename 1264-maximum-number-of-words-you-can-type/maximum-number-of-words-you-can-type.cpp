class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        int n = text.length();
        bool mp[26];
        for(char &ch : brokenLetters) {
            mp[ch-'a'] = true;
        }

        int result = 0;
        bool cantype=true;
        for(char &ch : text) {
            if(ch ==' ') //I have completed one word
            {
                if(cantype) {
                    result++;
                }
                cantype = true;//for the next word
            } else if (mp[ch - 'a']==true)//therefore broken character
            {
                cantype= false; //can't type the word
            }
        }

        if(cantype)//for the last word kyuki loop usse exceute hi nhi karega
            result++;

        return result;
        
    }
};