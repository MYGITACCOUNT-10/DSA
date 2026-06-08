class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller, larger, equal;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > pivot) {
                larger.push_back(nums[i]);
            } 
            else if (nums[i] < pivot) {  
                smaller.push_back(nums[i]);
            } 
            else {
                equal.push_back(nums[i]);
            }
        }

        vector<int> result;
        result.insert(result.end(), smaller.begin(), smaller.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), larger.begin(), larger.end());

        return result;
    }
};
