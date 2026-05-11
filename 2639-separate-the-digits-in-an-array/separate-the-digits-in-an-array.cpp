class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int>digits;

        for(int i=0;i<nums.size();i++)
        {
            int n=nums[i];
            vector<int>digit;
            while(n!=0)
            {
                int r=n%10;
                digit.push_back(r);
                n=n/10;
            }

            reverse(digit.begin(),digit.end());
            
            for(int j=0;j<digit.size();j++)
            {
                digits.push_back(digit[j]);
            }
        }

        return digits;
        
    }
};