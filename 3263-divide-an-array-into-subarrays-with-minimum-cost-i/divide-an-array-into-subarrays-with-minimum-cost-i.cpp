class Solution {
public:
    int minimumCost(vector<int>& nums) {

        long  cost=nums[0];

        sort(nums.begin()+1,nums.end());

        cost=cost+nums[1]+nums[2];

        return cost;
        
    }
};