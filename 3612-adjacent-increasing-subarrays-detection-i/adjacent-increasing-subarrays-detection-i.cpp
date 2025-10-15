class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        
        for (int i = 0; i + 2 * k <= len; i++) {
            bool first = true, second = true;

            // Check first subarray from i to i + k - 1
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] <= nums[j - 1]) {
                    first = false;
                    break;
                }
            }

            // If first is not increasing → skip checking the second
            if (!first) continue;

            // Check second subarray from i + k to i + 2k - 1
            for (int j = i + k + 1; j < i + 2 * k; j++) {
                if (nums[j] <= nums[j - 1]) {
                    second = false;
                    break;
                }
            }

            // If both increasing
            if (first && second)
                return true;
        }

        return false;
    }
};

//The first subarray uses indices: [i ... i + k - 1]
//The second subarray uses indices: [i + k ... i + 2*k - 1]

//The last index we touch = i + 2*k - 1
//That must be < len
//⟹ i + 2*k <= len