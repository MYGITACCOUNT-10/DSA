class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int remainder = 0; 

        for(int bit : nums) {
            // Update the remainder directly.
            // We apply % 5 here to prevent the number from growing.
            remainder = (remainder * 2 + bit) % 5;
            
            // Check if the remainder is 0
            if(remainder == 0) 
                result.push_back(true);
            else 
                result.push_back(false);
        }

        return result;
    }
};