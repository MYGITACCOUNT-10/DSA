class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int total_sum=0;

        vector<int>remainder_1;//Storing the smallest 2 number having the reminader as 1
        vector<int>remainder_2;//Storing the smallest 2 number having the reminader as 2

        for(int i=0;i<nums.size();i++)
        {   
            total_sum+=nums[i];
            int rem=nums[i]%3;
            if(remainder_1.size()!=2 && rem==1) remainder_1.push_back(nums[i]);
            if(remainder_2.size()!=2 && rem==2) remainder_2.push_back(nums[i]);
        }

        int rem=total_sum%3;
        if(rem==0) return total_sum;


        if(total_sum%3==1)
        {
            int remove_one = (remainder_1.size() >= 1) ? remainder_1[0] : 1e9;
            int remove_two_twos = (remainder_2.size() >= 2) ? remainder_2[0] + remainder_2[1] : 1e9;
        
        // Take the minimum loss
        total_sum -= min(remove_one, remove_two_twos);
        }

        if(total_sum%3==2)
        {
            int remove_two = (remainder_2.size() >= 1) ? remainder_2[0] : 1e9;
            int remove_two_ones = (remainder_1.size() >= 2) ? remainder_1[0] + remainder_1[1] : 1e9;
        
        // Take the minimum loss
        total_sum -= min(remove_two, remove_two_ones);
        }

        // else if(total_sum%3==1 && remainder_1.empty() && (remainder_2.size()==2)) total_sum=total_sum-remainder_2[0]-remainder_2[1];

        // else if(total_sum%3==2 && !remainder_2.empty()) total_sum-=remainder_2[0];

        // else if(total_sum%3==1 && remainder_2.empty() && (remainder_1.size()==2)) total_sum=total_sum-remainder_1[0]-remainder_1[1];
        
        return total_sum;
        
    }
};