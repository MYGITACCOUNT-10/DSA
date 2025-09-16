class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {

        vector<int>res;//we can use the stack

        //Processing left to right
        for(int num:nums)
        {
            while(!res.empty())
            {
                int prev=res.back();//Taking the last element we have inserted.
                int curr=num;

                int GCD=gcd(prev,curr);
                if(GCD==1) break;//Since the gcd is 1 ..therefore we can break the loop.

                //If the gcd is not one...we need to pop the last element and push the LCM of the prev & curr
                res.pop_back();

                int LCM=(prev/GCD*curr);
                num=LCM;
            }
            res.push_back(num);

        }

        return res;
        
    }
};