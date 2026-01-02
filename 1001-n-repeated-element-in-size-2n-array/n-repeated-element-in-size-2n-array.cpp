class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

       int required_f=nums.size()/2;

       unordered_map<int,int>mp;
       for(auto num:nums)
       {
        mp[num]++;
       }

        int ans;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==required_f) 
            {
                ans= it->first;
                break;
            }
        }

        return ans;
        
    }
};