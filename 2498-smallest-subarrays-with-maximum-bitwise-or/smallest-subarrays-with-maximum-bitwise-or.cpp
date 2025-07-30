class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {

        int n=nums.size();

        vector<int>result(n);

        vector<int>SetBitIndex(32,-1);
        //SetBitIndex[j]=i,it means jth bit can be set via element at index  i in nums

        for(int i=n-1;i>=0;i--)
        {   
             int endIndex=i;

            //nums[i]=binary rep
            for(int j=0;j<32;j++)
            {   
                if(!(nums[i] & (1 << j)))//if the jth bit is not set
                {
                    if(SetBitIndex[j]!= -1)
                    {
                        endIndex=max(endIndex,SetBitIndex[j]);
                    }
                }
                else
                {
                    SetBitIndex[j]=i;
                }

                result[i]=endIndex-i+1;
            }
        }

        return result;
        
    }
};