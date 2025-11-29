class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int total_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            total_sum+=nums[i];
        }
        int min_steps=total_sum%k;
       
       return min_steps;

    }
};