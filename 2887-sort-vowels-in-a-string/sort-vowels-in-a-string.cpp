class Solution {
private:
bool isvowel(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return true;
    else return false;
}
public:
    string sortVowels(string s) {

       string vowel;
       string consonant;

       for(char ch:s)
       {
            if(isvowel(ch)) vowel.push_back(ch);
            else consonant.push_back(ch);
       }

       sort(vowel.begin(),vowel.end());//arranged all the vowel in ascending order

       string result;
       int v=0;
       int c=0;
       for(auto ch:s)
       {
            if(isvowel(ch))
            {
                char vow=vowel[v];
                result.push_back(vow);
                v++;
            }
            else 
            {
                char con=consonant[c];
                result.push_back(con);
                c++;
            }
       }

       return result;
        
        
    }
};