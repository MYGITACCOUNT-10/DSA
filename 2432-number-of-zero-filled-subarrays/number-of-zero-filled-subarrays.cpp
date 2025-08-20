class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                int j = i;
                //The end of consecutive zeros
                while(j < n && nums[j] == 0) {
                    j++;
                }
                
                int consecutive = j - i;
                result += (long long)consecutive * (consecutive + 1) / 2;
                
                // Move i to the end of this zero sequence
                i = j - 1; // -1 because the for loop will increment i
            }
        }
        
        return result;
    }
};