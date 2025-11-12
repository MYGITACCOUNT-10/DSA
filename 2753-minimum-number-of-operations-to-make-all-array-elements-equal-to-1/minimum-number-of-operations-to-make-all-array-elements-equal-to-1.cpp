class Solution {
private:
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
public:
    int minOperations(vector<int>& nums) {

    int n=nums.size();
    //If one is present in the array
    int count_1=count(nums.begin(),nums.end(),1);
    if(count_1>0) return n-count_1;
   
    int min_ops=INT_MAX;
    int one_idx=-1;
    int min_len=INT_MAX;//minimum lenght of subarray whose gcd is 1
    for(int i=0;i<n;i++)
    {   
        int current_gcd=nums[i];
        for(int j=i+1;j<n;j++)
        {
            current_gcd=gcd(current_gcd,nums[j]);
//If you find a subarray nums[i...j] of length k whose GCD is 1, it will take k-1 operations to turn nums[i] into a 1.
            if(current_gcd==1)
            {
                min_len=min(min_len,j-i+1);//Got the subarray..no need to explore further
                break;
            }
        }
    }

   if(min_len==INT_MAX) return -1;

   return (min_len-1)+(n-1);
    
    
    }
};