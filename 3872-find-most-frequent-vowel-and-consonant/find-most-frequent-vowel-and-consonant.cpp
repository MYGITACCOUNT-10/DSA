class Solution {
public:
    int maxFreqSum(string s) {

        unordered_map<char,int>vowel;
        unordered_map<char,int>cons;

        for(auto ch:s)
        {
            if(ch=='a' || ch=='e'|| ch=='i' || ch=='o' || ch=='u') vowel[ch]++;
            else cons[ch]++;
        } 

        int max_vowel=0;
        int max_cons=0;

        for(auto it:vowel)
        {
            if(it.second>max_vowel) max_vowel=it.second;
        }    

        for(auto it:cons)
        {
            if(it.second>max_cons) max_cons=it.second;
        }  

        return max_vowel+max_cons;   
    }
};