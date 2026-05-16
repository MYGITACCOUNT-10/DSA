class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - i - 1];

            int mn = 1 + min(a, b);
            int mx = limit + max(a, b);

            int sum = a + b;

            // Initially assume 2 moves for all sums
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // One move range
            diff[mn] -= 1;
            diff[mx + 1] += 1;

            // Zero move at exact sum
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int curr = 0;

        for (int i = 2; i <= 2 * limit; i++) {

            curr += diff[i];

            ans = min(ans, curr);
        }

        return ans;
    }
};