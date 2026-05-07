class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        int n = nums.size();

        vector<int> maxprefix(n);
        vector<int> minsuffix(n);

        maxprefix[0] = nums[0];
        minsuffix[n-1] = nums[n-1];

        // maxprefix->abhi tak ka sabse bada element on left side
        for(int i = 1; i < n; i++) {
            maxprefix[i] = max(nums[i], maxprefix[i-1]);
        }

        // minsuffix->abhi tak sabse min element on right side
        for(int i = n-2; i >= 0; i--) {
            minsuffix[i] = min(nums[i], minsuffix[i+1]);
        }

        vector<int> ans(n);

        // last index ke liye right side no index
        ans[n-1] = maxprefix[n-1];

        for(int i = n-2; i >= 0; i--) {

            if(maxprefix[i] > minsuffix[i+1]) {
                ans[i] = ans[i+1];
            }
            else {
                ans[i] = maxprefix[i];
            }
        }

        return ans;
        
    }
};