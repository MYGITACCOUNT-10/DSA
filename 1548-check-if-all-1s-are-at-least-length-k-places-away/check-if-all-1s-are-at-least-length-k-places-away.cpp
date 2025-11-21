class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        vector<int>occurences;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1) occurences.push_back(i);
        }

        if(occurences.size()<2) return true;
        else {for(int i=0;i<occurences.size()-1;i++)
        {
            if(occurences[i+1]-occurences[i]<=k) return false;
        }
        }
        
        return true;
    }
};