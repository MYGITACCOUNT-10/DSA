class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        set<int>s(nums.begin(),nums.end());

        int item=original;
        while(s.find(item)!=s.end())
        {
            item=item*2;
        }
        
        return item;
    }
};