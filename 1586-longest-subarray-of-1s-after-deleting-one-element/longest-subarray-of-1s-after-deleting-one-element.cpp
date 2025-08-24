class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int curr_zeroes=0;
        int left=0;
        int max_ones=INT_MIN;

        for(int right=0;right<nums.size();right++)
        {
            if(nums[right]==0) curr_zeroes++;

            //deleteing 0 means my window should have atmost 1 zero for deletion and coputing teh subarray
            while(curr_zeroes>1)
            {   
                if(nums[left]==0) curr_zeroes--;
                left++;
            }

            max_ones=max(max_ones,right-left+1);
        }

        //max_ones will give me the longest subarrau which consist of 1-zero adn rest all are one
        //Therefore..we need to delete zero and give the answer
        return max_ones-1;
        
    }
};