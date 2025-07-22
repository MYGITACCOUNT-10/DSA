class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int ma_score=0;
        set<int>s;
        int left=0;
        int right=0;
        int max_score=INT_MIN;
        int score=0;

        int n=nums.size();

        while(right<n){
            int val=nums[right];
            auto found = s.find(val);//found iterator for finding the element in set
            while(found != s.end())
            {   
                score-=nums[left];
                s.erase(nums[left]);// Deleting elements by value
                left++;
                found = s.find(val); // Re-check after removing elements
            }

            s.insert(nums[right]);
            score+=nums[right];
            max_score=max(score,max_score);

            right++;
            
        }

        return max_score;
        
    }
};