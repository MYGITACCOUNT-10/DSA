class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>prefix(n,0);
        prefix[0]=nums[0];

        for (int i = 1; i < n; i++) 
        {
            prefix[i]=nums[i]+prefix[i-1];
        }

        vector<int>suffix(n,0);
        suffix[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]+nums[i];
        }

        int pivot=-1;

        for(int i=0;i<n;i++)
        {
            if(suffix[i]==prefix[i])
            {
                pivot=i;
                break;
            }
        }

        return pivot;
    }
};
