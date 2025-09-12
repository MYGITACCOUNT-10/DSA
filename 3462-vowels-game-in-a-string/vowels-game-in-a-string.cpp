class Solution {
public:
    bool doesAliceWin(string s) {
        for(char x:s){
            if(x=='a' || x=='e'  || x=='i'  || x=='o'  || x=='u'){
                return true;
            }
        }
        return false;
    }
};

//Bob only wins when there are no vowels and Alice cant make a move in the very first turn.

//If there are even number of vowels, Alice take odd number of vowels in a substring and Bob is left with odd number of vowels too. (Since an even number is a sum of 2 odd numbers). Hence Bob is unable to make a move and loses.