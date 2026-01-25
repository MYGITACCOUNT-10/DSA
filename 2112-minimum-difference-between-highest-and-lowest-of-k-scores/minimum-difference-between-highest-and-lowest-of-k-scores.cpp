class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

    //From all possible groups of k students, find the group where the gap between the highest and lowest scores is smallest, and return that gap

    sort(nums.begin(), nums.end());

    int min_diff = INT_MAX;

    for (int left = 0; left <= nums.size() - k; left++)
        {
    int right = left + k - 1;
    int diff = nums[right] - nums[left];
    min_diff = min(min_diff, diff);
}

return min_diff;
    }
};