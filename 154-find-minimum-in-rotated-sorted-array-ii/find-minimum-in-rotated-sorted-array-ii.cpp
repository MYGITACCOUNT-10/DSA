class Solution {
public:
    int findMin(vector<int>& nums) {

         int left=0;
        int right=nums.size()-1;
        int min_ele=INT_MAX;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(nums[left]==nums[mid] && nums[mid]==nums[right])
            {  min_ele = min(min_ele, nums[left]);//comparing it beacuse array can conatin[1] or[2,2,2,2]
                left++;
                right--;
            }

            else 
            {
              if(nums[mid]>=nums[left])
            {
                min_ele=min(min_ele,nums[left]);
                left=mid+1;
            }
             else 
            {
                min_ele=min(min_ele,nums[mid]);
                right=mid-1;;

            }
            }
        }
         return min_ele;
        
    }
};