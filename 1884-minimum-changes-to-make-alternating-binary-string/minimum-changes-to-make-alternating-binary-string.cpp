class Solution {
public:
    int minOperations(string s) {

        int alt1 = 0, alt2 = 0;

        int prev1 = 0; // assume pattern starts with 0
        int prev2 = 1; // assume pattern starts with 1

        for(int i = 0; i < s.size(); i++)
        {
            int curr = s[i] - '0';

            if(curr != prev1)
                alt1++;

            if(curr != prev2)
                alt2++;

            prev1 = 1 - prev1;
            prev2 = 1 - prev2;
        }

        return min(alt1, alt2);
    }
};