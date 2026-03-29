class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        for(int i = 0; i < 4; i++) {
            bool found = false;
            
            //  same position
            if(s1[i] == s2[i]) found = true;
            
            //  i+2
            if(i + 2 < 4 && s1[i] == s2[i + 2]) found = true;
            
            //  i-2
            if(i - 2 >= 0 && s1[i] == s2[i - 2]) found = true;
            
            if(!found) return false;
        }
        
        return true;
    }
};