class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int operations=0;
        for(int i=0;i<nums.size();i++)
        {
            operations+= min(nums[i] % 3, 3 - (nums[i] % 3));
        }
        return operations;
        
    }
};