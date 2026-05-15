class Solution {
public:
    bool isGood(vector<int>& nums) {

        int max_ele=*max_element(nums.begin(),nums.end());
        int len=nums.size();

        if(len!=(max_ele+1)) return false;
        
        vector<int>v;

        for(int i=1;i<max_ele+1;i++)
        {   
            v.push_back(i);

        }
        v.push_back(max_ele);

        sort(nums.begin(),nums.end());

        return v==nums;


        
    }
};