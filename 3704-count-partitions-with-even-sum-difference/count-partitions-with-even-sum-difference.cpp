class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int n=nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);

        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=nums[i]+prefix[i-1];
        }

        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]+nums[i];
        }

        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            int left_sum=prefix[i];
            int right_sum=suffix[i]-nums[i];

            if(abs(left_sum-right_sum)%2==0) cnt++;
        }

        return cnt;
        

    }
};