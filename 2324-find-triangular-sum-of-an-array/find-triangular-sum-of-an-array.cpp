class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        vector<int>v_old=nums;
        while(v_old.size()>1)
        {   
            int n=v_old.size();
            vector<int>v_current_iteration(n-1);
            for(int i=0;i<v_old.size()-1;i++)
            {
                v_current_iteration[i]=(v_old[i]+v_old[i+1])%10;
            }
            v_old=v_current_iteration;
        }

        return v_old[0];
    }
};